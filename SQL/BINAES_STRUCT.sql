--FECHA DE PRESTAMO, SOLICITUD Y DEVOLUCION DIFERENTE DE NULL
DROP DATABASE BINAES;
GO
--CREACION DE BASE DE DATOS
CREATE DATABASE BINAES;
GO
USE BINAES;
GO
--CREACION DE ESTRUCTURA
CREATE TABLE EVENTO(
    id INT
        PRIMARY KEY NOT NULL,
    --ATRIBUTOS
    titulo VARCHAR(50),
    imagen VARCHAR,
    asistentes INT,
    hora_inicio DATETIME,
    hora_final DATETIME,
    fecha_inicio DATETIME,
    fecha_final DATETIME,
    --FK
    id_area INT NOT NULL
);
GO

CREATE TABLE OBJETIVO(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    --FK
    id_evento INT NOT NULL
);
GO

CREATE TABLE ACTIVIDAD(
    id INT
        PRIMARY KEY NOT NULL,
    --FK
    id_area INT NOT NULL,
    id_evento INT NOT NULL,
    id_asistencia INT NOT NULL
);
GO

CREATE TABLE AREA(
    id INT
        PRIMARY KEY NOT NULL,
    --ATRIBUTOS
    nombre VARCHAR(50),
    descripcion VARCHAR(100),
    horario DATETIME NOT NULL,
    --FK
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
    --ATRIBUTOS
    nombre VARCHAR(50),
    direccion VARCHAR(100),
    telefono CHAR(12) 
        NOT NULL 
        UNIQUE 
        CHECK (telefono LIKE '+503[2|6|7][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    fotografia VARCHAR,
    correo VARCHAR(50),
    --FK
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
    id INT 
        PRIMARY KEY NOT NULL,
    --ATRIBUTOS
    fecha_entrada DATETIME,
    fecha_salida DATETIME,
    hora_entrada DATETIME,
    hora_salida DATETIME,
    --FK
    id_actividad INT NOT NULL,
    id_usuario INT NOT NULL,
);
GO

CREATE TABLE PRESTAMO_RESERVA(
    id INT 
        PRIMARY KEY NOT NULL,
    --ATRIBUTOS
    fecha_reserva DATETIME,
    hora_reserva DATETIME,
    fecha_devolucion DATETIME,
    hora_devolucion DATETIME,
    fecha_prestamo DATETIME,
    hora_prestamo DATETIME,
    --FK
    id_usuario INT NOT NULL,
    id_ejemplar INT NOT NULL,
);
GO

CREATE TABLE EJEMPLAR(
    id INT
        PRIMARY KEY NOT NULL,
    --ATRIBUTOS
    nombre VARCHAR(50),
    imagen VARCHAR,
    publicacion DATE,
    --FK
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
    --FK
    id_ejemplar INT NOT NULL
);
GO

CREATE TABLE LISTA_PALABRAS(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    --FK
    id_ejemplar INT NOT NULL
);
GO

CREATE TABLE ETIQUETA(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    --FK
    id_ejemplar INT NOT NULL
);
GO

CREATE TABLE COLECCION(
    id INT
        PRIMARY KEY NOT NULL,
    nombre VARCHAR(50),
    --FK
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