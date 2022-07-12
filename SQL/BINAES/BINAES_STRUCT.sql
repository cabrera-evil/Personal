use master;
GO
DROP DATABASE BINAES;
--******************************************************* DATA BASE CREATION ******************************************************
CREATE DATABASE BINAES;
GO
USE BINAES;
GO
--******************************************************* TABLE'S CREATION ******************************************************
CREATE TABLE CELEBRATION(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    --ATRIBUTOS
    title VARCHAR(50) NOT NULL,
    picture VARBINARY(MAX),
    attendance INT,
    beginning_hour DATETIME,
    finishing_hour DATETIME,
    beginning_date DATETIME,
    finishing_date DATETIME,
);
GO

CREATE TABLE FLOOR_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    floor_number VARCHAR(50) NOT NULL
);
GO

CREATE TABLE GOAL(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    goal_name VARCHAR(150) NOT NULL, 
    --FK
    id_celebration INT NOT NULL
);
GO

CREATE TABLE ACTIVITY(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    --FK
    id_area INT NOT NULL,
    id_celebration INT,
    id_attendance INT NOT NULL
);
GO

CREATE TABLE AREA(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    --ATRIBUTOS
    area_name VARCHAR(50) NOT NULL,
    area_description VARCHAR(300),
    schedule VARCHAR(30),
    --FK
    id_manager INT DEFAULT 'No defined',
	id_floor INT NOT NULL
);
GO

CREATE TABLE MANAGER(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    manager_name VARCHAR(50) NOT NULL
);
GO

CREATE TABLE USER_(
    id INT 
        IDENTITY(1,1) PRIMARY KEY,
    --ATRIBUTOS
	full_name VARCHAR (50) NOT NULL,
    username VARCHAR(20) NOT NULL UNIQUE,
    user_address VARCHAR(100) NULL
        DEFAULT 'No defined',
    phone CHAR(13) 
        NOT NULL 
        UNIQUE 
        CHECK (phone LIKE '+503 [2|6|7][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    picture VARBINARY(MAX),
    email VARCHAR(50) UNIQUE,
    password VARCHAR(256),
    --FK
    id_occupancy INT NOT NULL,
    id_institution INT NOT NULL,
    id_role INT NOT NULL
);
GO

CREATE TABLE OCCUPANCY(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    occupancy_name VARCHAR(50) -- NOT NULL UNIQUE
);
GO

CREATE TABLE ROLE_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    role_type VARCHAR(50)
);
GO

CREATE TABLE INSTITUTION(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    institution_name VARCHAR(50) NOT NULL
);
GO

CREATE TABLE ATTENDANCE(
    id INT 
        IDENTITY(1,1) PRIMARY KEY,
    --ATRIBUTOS
    entrance_date DATETIME,
    exit_date DATETIME,
    entarance_hour DATETIME,
    exit_hour DATETIME,
    --FK
    id_user INT NOT NULL,
);
GO

CREATE TABLE LOAN_BOOKING(
    id INT 
        IDENTITY(1,1) PRIMARY KEY,
    --ATRIBUTOS
    booking_date DATETIME,
    booking_hour DATETIME,
    return_date DATETIME,
    return_hour DATETIME,
    loan_date DATETIME,
    loan_hour DATETIME,
    --FK
    id_user INT NOT NULL,
    id_copy INT NOT NULL,
);
GO

CREATE TABLE COPY_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    --ATRIBUTOS
    copy_name VARCHAR(50) NOT NULL,
    picture VARBINARY(MAX),
    release_date DATETIME,
    --FK
    id_collection INT NOT NULL,
    id_language INT,
    id_format INT,
	id_editorial INT
);
GO

CREATE TABLE EDITORIAL(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    editorial_name VARCHAR(50) NOT NULL
);
GO

CREATE TABLE LANGUAGE_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    language_name VARCHAR(50) NOT NULL
);
GO

CREATE TABLE FORMAT_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    format_name VARCHAR(50) NOT NULL
);
GO

CREATE TABLE AUTHOR(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    author_name VARCHAR(50) NOT NULL,
    --FK
    id_copy INT NOT NULL
);
GO

CREATE TABLE WORDS_LIST(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    word VARCHAR(50) NOT NULL,
    --FK
    id_copy INT NOT NULL
);
GO

CREATE TABLE LABEL_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    label_code VARCHAR(50) NOT NULL DEFAULT 'None',
    --FK
    id_copy INT NOT NULL,
	id_label_type INT NOT NULL
);
GO

CREATE TABLE LABEL_TYPE(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    label_name VARCHAR(4) NOT NULL
);
GO


CREATE TABLE COLLECTION_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    collection_name VARCHAR(150) NOT NULL,
    --FK
    id_type INT,
    id_genre INT
);
GO

CREATE TABLE TYPE_(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    type_name_ VARCHAR(50) NOT NULL
);
GO

CREATE TABLE GENRE(
    id INT
        IDENTITY(1,1) PRIMARY KEY,
    genre_name VARCHAR(50) NOT NULL
);
GO
--******************************************************* FOREIGN KEYS CREATION ******************************************************
--COLLECTION_ TABLE
ALTER TABLE COLLECTION_ ADD CONSTRAINT fk_collection_genre
	FOREIGN KEY(id_genre) REFERENCES GENRE(id); 
GO    
ALTER TABLE COLLECTION_ ADD CONSTRAINT fk_collection_type
	FOREIGN KEY(id_type) REFERENCES TYPE_(id); 
GO
-- WORDS_LIST TABLE
ALTER TABLE WORDS_LIST ADD CONSTRAINT fk_copy_list
	FOREIGN KEY(id_copy) REFERENCES COPY_(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
-- AUTHOR TABLE
ALTER TABLE AUTHOR ADD CONSTRAINT fk_copy_author
	FOREIGN KEY(id_copy) REFERENCES COPY_(id); 
GO
-- COPY_ TABLE
ALTER TABLE COPY_ ADD CONSTRAINT fk_collection_copy
	FOREIGN KEY(id_collection) REFERENCES COLLECTION_(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
ALTER TABLE COPY_ ADD CONSTRAINT fk_copy_language
	FOREIGN KEY(id_language) REFERENCES LANGUAGE_(id);
GO
ALTER TABLE COPY_ ADD CONSTRAINT fk_copy_format
	FOREIGN KEY(id_format) REFERENCES FORMAT_(id);
GO
ALTER TABLE COPY_ ADD CONSTRAINT fk_copy_editorial
	FOREIGN KEY(id_editorial) REFERENCES EDITORIAL(id);
GO
-- USER_ TABLE
ALTER TABLE USER_ ADD CONSTRAINT fk_user_intitution
	FOREIGN KEY(id_institution) REFERENCES INSTITUTION(id);
GO
ALTER TABLE USER_ ADD CONSTRAINT fk_user_occupancy
	FOREIGN KEY(id_occupancy) REFERENCES OCCUPANCY(id);
GO
ALTER TABLE USER_ ADD CONSTRAINT fk_user_role
	FOREIGN KEY(id_role) REFERENCES ROLE_(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;;
GO
-- AREA TABLE
ALTER TABLE AREA ADD CONSTRAINT fk_area_manager
	FOREIGN KEY(id_manager) REFERENCES MANAGER(id);
GO
ALTER TABLE AREA ADD CONSTRAINT fk_area_floor
	FOREIGN KEY(id_floor) REFERENCES FLOOR_(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
-- GOAL TABLE
ALTER TABLE GOAL ADD CONSTRAINT fk_goal_event
	FOREIGN KEY(id_celebration) REFERENCES CELEBRATION(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
--******************************************************* CROSS TABLES ******************************************************
-- LABEL_ TABLE
ALTER TABLE LABEL_ ADD CONSTRAINT fk_copy_label
	FOREIGN KEY(id_copy) REFERENCES COPY_(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
ALTER TABLE LABEL_ ADD CONSTRAINT fk_type_label
	FOREIGN KEY(id_label_type) REFERENCES LABEL_TYPE(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
-- LOAN_BOOKING TABLE
ALTER TABLE LOAN_BOOKING ADD CONSTRAINT fk_user_lxb
    FOREIGN KEY(id_user) REFERENCES USER_(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
ALTER TABLE LOAN_BOOKING ADD CONSTRAINT fk_copy_lxb
    FOREIGN KEY(id_copy) REFERENCES COPY_(id)
	ON DELETE NO ACTION
    ON UPDATE NO ACTION;
GO
-- ACTIVITY TABLE
ALTER TABLE ACTIVITY ADD CONSTRAINT fk_activity_area
    FOREIGN KEY(id_area) REFERENCES AREA(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
ALTER TABLE ACTIVITY ADD CONSTRAINT fk_event_activity
    FOREIGN KEY(id_celebration) REFERENCES CELEBRATION(id);
GO 
ALTER TABLE ACTIVITY ADD CONSTRAINT fk_activity_attendance
    FOREIGN KEY(id_attendance) REFERENCES ATTENDANCE(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO 
-- ATTENDANCE TABLE
ALTER TABLE ATTENDANCE ADD CONSTRAINT fk_attendance_user
    FOREIGN KEY(id_user) REFERENCES USER_(id)
	ON DELETE CASCADE
    ON UPDATE CASCADE;
GO
USE master;