--****************************************************
-- Bases de datos: Triggers
-- Autor: Erick Varela
-- Correspondencia: evarela@uca.edu.sv
-- Version: 1.0
--****************************************************
SELECT * FROM CLIENTE;
SELECT * FROM RESERVA ORDER BY id DESC;
DELETE FROM RESERVA WHERE id > 200;
-- *****************************************************
-- 1.	Procedimientos almacenados y triggers
-- *****************************************************
-- 1.1.	Crear un procedimiento almacenado que permita registrar nuevas reservas.
--		Como argumentos se reciben: el la fecha de checkin y checkout, el id de metodo de pago, el id del cliente
--		y el id de la habitacion.
--		NOTA: Validar que la nueva reserva no se solape con otras reservas

CREATE OR ALTER PROCEDURE BOOKING_02 
    @id INT, 
    @checkin VARCHAR(12), 
    @checkout VARCHAR(12), 
    @id_metodo_pago INT, 
    @id_cliente INT, 
    @id_habitación INT
AS 
BEGIN
    BEGIN TRY
        INSERT INTO RESERVA 
            VALUES (@id, CONVERT(DATE, @checkin, 103), CONVERT(DATE, @checkout, 103), @id_metodo_pago, @id_cliente, @id_habitación);
    END TRY 
    BEGIN CATCH
        PRINT ERROR_MESSAGE();
    END CATCH;
END; 


CREATE OR ALTER TRIGGER CHECK_BOOKING
ON RESERVA
AFTER INSERT
AS BEGIN
    -- Declarando variables
    DECLARE @checkin DATE;
    DECLARE @checkout DATE;
    DECLARE @id_habitacion INT;
    DECLARE @resultado INT;

    -- Obteniendo datos de la reserva que se espera insertar
    SELECT @checkin = i.checkin, @checkout = i.checkout, @id_habitacion = i.id_habitacion FROM INSERTED i; 

    -- Evaluando si la reserva es válida
    SELECT @resultado = COUNT(*) FROM RESERVA 
    WHERE 
        ((@checkin >= checkin AND @checkout <= checkout) OR
        (@checkin < checkin AND @checkout > checkout ) OR
        (@checkin < checkin AND (@checkout BETWEEN checkin AND checkout)) OR
        ((@checkin BETWEEN checkin AND checkout) AND @checkout > checkout)) AND
        id_habitacion = @id_habitacion;

    IF @resultado > 1 
    BEGIN 
        RAISERROR ('ERROR: las fechas establecidas coinciden con otra reserva. Reserva inválida',11,1);
        ROLLBACK TRANSACTION;
    END; 
END;


/*
INSERTED
INSERT: se almacenan los datos que se estan insertando
DELETE: no almacena datos
UPDATE: se almacenan los datos nuevos (despues de la actualización)
DELETED
INSERT: no almacena datos
DELETE: se almacenan los datos que se estan eliminado
UPDATE: se almacenan los datos antiguos (antes de la actualización)
*/



-- Ejecutando procedimiento almacenado
-- DELETE FROM RESERVA WHERE id = 201 OR id = 202;
EXEC BOOKING_02 201, '01/07/2022', '05/07/2022',1,13,3; --funciona
EXEC BOOKING_02 202, '01/07/2022', '05/07/2022',2,9,3; 
EXEC BOOKING_02 202, '04/07/2022', '08/07/2022',2,9,3;
EXEC BOOKING_02 202, '29/06/2022', '02/07/2022',2,9,3;
EXEC BOOKING_02 202, '29/06/2022', '02/07/2022',2,9,5; -- Funciona

SELECT * FROM RESERVA ORDER BY id DESC;


-- 1.2.	Crear una tabla llamada "REGISTRO_PUNTOS_S#", el objetivo de esta tabla será funcionar
--		como registro de los intercambios de puntos de cliente frecuente que realizan los
--		clientes. La tabla debe almacenar: la fecha y hora de la transaccion, el id y nombre del
--		usuario involucrado, la cantidad de puntos antes y despues de la transacción y una 
--		descriptión breve del proceso realizado.


CREATE TABLE REGISTRO_PUNTOS_S02 (
    id INT PRIMARY KEY IDENTITY,
    fecha DATETIME,
    id_cliente INT,
    nombre_cliente VARCHAR(64),
    puntos_inicial INT,
    puntos_final INT, 
    descripcion VARCHAR(256)
);

SELECT * FROM REGISTRO_PUNTOS_S02;

CREATE OR ALTER PROCEDURE TRANSFERIR_PUNTOS_02
    @id_emisor INT,
    @id_receptor INT,
    @puntos INT
AS BEGIN
    -- Validando si los puntos del cliente emisor son suficiente para realizar la transfencia
    DECLARE @puntos_cliente_emisor INT;
    SELECT @puntos_cliente_emisor = puntos_cliente_frecuente FROM CLIENTE WHERE id = @id_emisor;
    IF @puntos_cliente_emisor < @puntos 
        BEGIN
            PRINT 'ERROR: El cliente no tiene suficientes puntos para ser transferidos :(';
        END
    ELSE   
        BEGIN
            BEGIN TRY 
                -- Restando puntos al emisor
                UPDATE CLIENTE SET puntos_cliente_frecuente = puntos_cliente_frecuente - @puntos 
                    WHERE id = @id_emisor;
                -- Sumando puntos al receptor
                UPDATE CLIENTE SET puntos_cliente_frecuente = puntos_cliente_frecuente + @puntos 
                    WHERE id = @id_receptor;
            END TRY
            BEGIN CATCH
                DECLARE @ERROR_MESSAGE VARCHAR(100);
                SELECT @ERROR_MESSAGE = ERROR_MESSAGE();
                PRINT 'ERROR OCURRIDO: '+ @ERROR_MESSAGE;
            END CATCH; 
        END; 
END;


CREATE OR ALTER TRIGGER CHECK_CLIENT_POINTS 
ON CLIENTE
AFTER UPDATE 
AS BEGIN
    -- Seccion de declaracion de variables
    DECLARE @fecha DATETIME;
    DECLARE @id_cliente INT;
    DECLARE @nombre_cliente VARCHAR(64);
    DECLARE @puntos_inicial INT;
    DECLARE @puntos_final INT;
    DECLARE @descripcion VARCHAR(256);

    -- Obteniendo fecha
    SELECT @fecha = GETDATE();
    -- Obteniendo los puntos antes de la actualización
    SELECT @id_cliente = id, @nombre_cliente = nombre, @puntos_inicial = puntos_cliente_frecuente FROM DELETED; 
    -- Obteniendo los puntos despues de la actualización
    SELECT @puntos_final = puntos_cliente_frecuente FROM INSERTED; 
    -- Definiendo descripcion del evento
    IF @puntos_inicial > @puntos_final 
    BEGIN
        SET @descripcion = 'El cliente ha gastado o transferido puntos';
    END
    ELSE
    BEGIN 
        SET @descripcion = 'El cliente ha recibido puntos';
    END;

    INSERT INTO REGISTRO_PUNTOS_S02 (fecha, id_cliente, nombre_cliente, puntos_inicial, puntos_final, descripcion)
        VALUES(@fecha, @id_cliente, @nombre_cliente, @puntos_inicial, @puntos_final, @descripcion);
END;


-- Verificando datos
SELECT * FROM CLIENTE WHERE id = 1 OR id = 2;
EXEC TRANSFERIR_PUNTOS 2,1, 2000;
SELECT * FROM CLIENTE WHERE id = 1 OR id = 2;
-- Verificando contenido de la tabla REGISTRO_PUNTOS
SELECT * FROM REGISTRO_PUNTOS_S02;

EXEC TRANSFERIR_PUNTOS 1,2, 100;
SELECT * FROM CLIENTE WHERE id = 1 OR id = 2;
SELECT * FROM REGISTRO_PUNTOS_S02;