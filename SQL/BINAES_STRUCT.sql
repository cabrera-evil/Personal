--FECHA DE PRESTAMO, SOLICITUD Y DEVOLUCION DIFERENTE DE NULL

--CREACION DE BASE DE DATOS
CREATE DATABASE BINAES;
GO
USE BINAES;
GO
--CREACION DE ESTRUCTURA
CREATE TABLE EVENTO(
    id INT
        PRIMARY KEY NOT NULL,
    titulo VARCHAR(50),
    imagen VARCHAR,
    asistentes INT,
    hora_inicio DATETIME,
    hora_final DATETIME,
    fecha_inicio DATETIME,
    fecha_final DATETIME,
    id_area INT NOT NULL
);
GO

CREATE TABLE OBJETIVO(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    id_evento INT NOT NULL
);
GO

CREATE TABLE AREA(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    descripcion VARCHAR(100),
    horario DATETIME NOT NULL,
    id_responsable INT NOT NULL
);
GO

CREATE TABLE RESPONSABLE(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50)
);
GO

CREATE TABLE USUARIO(
    id INT 
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    direccion VARCHAR(100),
    telefono CHAR(12) 
        NOT NULL 
        UNIQUE 
        CHECK (telefono LIKE '+503[2|6|7][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    fotografia VARCHAR,
    correo VARCHAR(50),
    id_ocupacion INT NOT NULL,
    id_institucion INT NOT NULL
);
GO

CREATE TABLE OCUPACION(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50)
);
GO

CREATE TABLE INSTITUCION(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50)
);
GO

CREATE TABLE ASISTENCIA(
    --PKFK
    id_area INT NOT NULL,
    id_usuario INT NOT NULL,
    
    fecha_entrada DATETIME,
    fecha_salida DATETIME,
    hora_entrada DATETIME,
    hora_salida DATETIME
);
GO

CREATE TABLE PRESTAMO_RESERVA(
    id_usuario INT NOT NULL,
    id_ejemplar INT NOT NULL,

    fecha_reserva DATETIME,
    hora_reserva DATETIME,
    fecha_devolucion DATETIME,
    hora_devolucion DATETIME,
    fecha_prestamo DATETIME,
    hora_prestamo DATETIME
);
GO

CREATE TABLE EJEMPLAR(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    imagen VARCHAR,
    publicacion DATE,
    id_coleccion INT NOT NULL,
    id_idioma INT NOT NULL,
    id_formato INT NOT NULL
);
GO

CREATE TABLE IDIOMA(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50)
);
GO

CREATE TABLE FORMATO(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50)
);
GO

CREATE TABLE AUTOR(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    id_ejemplar INT NOT NULL
);
GO

CREATE TABLE LISTA_PALABRAS(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    id_ejemplar INT NOT NULL
);
GO

CREATE TABLE ETIQUETA(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    id_ejemplar INT NOT NULL
);
GO

CREATE TABLE COLECCION(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    id_tipo INT NOT NULL,
    id_genero INT NOT NULL
);
GO

CREATE TABLE TIPO(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50)
);
GO

CREATE TABLE GENERO(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50)
);

--SHOW TABLES
/*
SELECT * FROM USUARIO;
SELECT * FROM AREA;
SELECT * FROM EVENTO;
SELECT * FROM COLECCIONE;
SELECT * FROM EJEMPLAR;*/