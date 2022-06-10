--****************************************************
-- Nombre: Douglas Cabrera 
-- Carnet: 00133121
--****************************************************

/*Ejercicio 1. Los clientes VIP tienen acceso a una serie de servicios adicionales en los distintos aeropuertos que visitan, 
por lo que se solicita que defina la lista de clientes VIP. El criterio de evaluación consiste en verificar que el promedio 
de las reservas realizadas por un cliente sea mayor a 1799.00. En la evaluación se debe tener en cuenta todos los servicios 
extra que incluyan los clientes en las reservas. Restricción : El ejercicio debe realizarse en una consulta SELECT, sin 
utilizar la sentencia INTO, tablas temporales o bloques de programación (bloques anónimos, funciones o procedimientos almacenados). 
Resultado esperado:*/

SELECT T.id 'id_pasajero', T.nombre 'nombre_pasajero', AVG(T.costo + T.total)  'promedio de reservas'
FROM (
    SELECT P.id, P.nombre, R.costo, ISNULL(SUM(S.precio), 0) AS total
    FROM RESERVA R
    INNER JOIN PASAJERO P
        ON P.id = R.id_pasajero
    LEFT JOIN EXTRA E
        ON E.id_reserva = R.id
    LEFT JOIN SERVICIO S
        ON S.id = E.id_servicio
    GROUP BY P.id, P.nombre, R.costo
) AS T
GROUP BY T.id, T.nombre
HAVING AVG(T.costo + T.total) > 1799.00
ORDER BY T.id ASC;

/*Ejercicio 2. Cada reserva tiene una fecha en la que fue realizada, una solicitud del departamento de finanzas del consorcio requiere 
la ganancia del mes de abril de 2021, pero los datos deben estar organizados por días. Como parte de la solicitud, se requiere que la fecha 
sea mostrada en un formato especial (ver imagen de vista esperada). Para calcular el valor de una reserva se debe tomar en cuenta tanto el precio 
de la reserva como la suma de todos los servicios extras incluidos. Restricción : El ejercicio debe realizarse en una consulta SELECT, sin utilizar 
la sentencia INTO, tablas temporales o bloques de programación (bloques anónimos, funciones o procedimientos almacenados). Sugerencia : Investigar 
sobre la instrucción CONVERT y su utilización en la instrucción SELECT. Sección del resultado esperado (El resultado contiene más filas)*/

SELECT CONVERT(VARCHAR, T.fecha, 6) AS 'fecha', SUM(T.costo + T.total) AS 'ganancia del dia'
FROM (
    SELECT R.fecha, R.costo, ISNULL(SUM(S.precio), 0) AS total
    FROM RESERVA R
    LEFT JOIN EXTRA E
        ON E.id_reserva = R.id
    LEFT JOIN SERVICIO S
        ON S.id = E.id_servicio
    GROUP BY R.fecha, R.costo
) AS T
GROUP BY T.fecha
HAVING T.fecha BETWEEN '2021-04-01' AND '2021-04-30'; 

/*Ejercicio 3. La legislación internacional exige incluir un impuesto que depende de la clase seleccionada para cada reserva, 
la distribución actual impone los siguientes porcentajes:
Por lo que se requiere mostrar las reservas realizadas, pero incluyendo el precio de cada reserva más el impuesto aplicado según la clase. 
Se deben mostrar los siguientes campos: el id de la reserva, la fecha, el id de la clase, el nombre de la clase, el total de la reserva sin 
impuesto aplicado y el total con el impuesto aplicado. Debe recordar que el total de la reserva se define a partir del precio de la reserva
más la suma de todos los servicios extras incluidos. Restricciones : El ejercicio debe realizarse en una consulta SELECT, sin utilizar la 
sentencia INTO, tablas temporales o bloques de programación (bloques anónimos, funciones o procedimientos almacenados). Sugerencia : 
Investigar sobre la instrucción CASE y su utilización en la instrucción SELECT. Nota : El total de cada reserva se calcula de la siguiente forma: 
costo de la reserva + (suma de todos los servicios extra contratados). Tener en cuenta que no todas las reservas incluyen servicios extras. 
Sección del resultado esperado (el resultado contiene más filas):*/

SELECT R.id 'id_reserva', R.fecha, C.id, C.clase 'clase', (R.costo + SUM(ISNULL(S.precio, 0))) 'total(sin impuesto)',
CAST(CASE
    WHEN C.id LIKE '1' THEN (R.costo + ISNULL(SUM(S.precio), 0)) * 1.07
    WHEN C.id LIKE '2' THEN (R.costo + ISNULL(SUM(S.precio), 0)) * 1.11
    WHEN C.id LIKE '3' THEN (R.costo + ISNULL(SUM(S.precio), 0)) * 1.15
    END AS float) 'total(con impuesto aplicado)'
FROM RESERVA R
INNER JOIN CLASE C
    ON C.id = R.id_clase
LEFT JOIN EXTRA E
    ON E.id_reserva = R.id
LEFT JOIN SERVICIO S
    ON S.id = E.id_servicio
GROUP BY R.id, R.fecha, C.id, C.clase, R.costo
ORDER BY R.id ASC;