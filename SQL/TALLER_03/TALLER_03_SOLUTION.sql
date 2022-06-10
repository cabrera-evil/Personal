--****************************************************
-- Integrantes: Douglas Cabrera 
--              Diana Cruz
--              Carlos Marroquin
--****************************************************

/*Ejercicio 1 (5%). Mostrar la lista de clientes que han contratado el plan "Premium". Ordenar el
resultado con respecto al id del cliente en orden ascendente. Almacenar el resultado en una nueva
tabla llamada "CLIENTES_PREMIUM".*/

SELECT C.id, C.nombre, C.direccion, TP.tipo
FROM CLIENTE C
INNER JOIN TIPO_PLAN TP
	ON C.id_tipo_plan = TP.id
WHERE TP.tipo LIKE 'Premium'
ORDER BY C.id ASC

/*2. Mostrar las 2 clínicas más populares. El parámetro de popularidad se define en base al número de
citas registradas por cada clínica. Mostrar el id de la clínica, el nombre, su dirección y email, además
mostrar la cantidad de citas registradas. Ordenar el resultado en base a la cantidad de citas
registradas.*/

SELECT TOP 2 CL.id, CL.nombre, CL.direccion, CL.email, COUNT(C.id_clinica) "Numero de citas"
FROM CLINICA CL
INNER JOIN CITA C
	ON C.id_clinica = CL.id
GROUP BY CL.id, CL.nombre, CL.direccion, CL.email
ORDER BY 'Numero de citas' DESC

/*3. Mostrar la información completa de cada cliente, incluir el nombre, dirección, el tipo de plan, los
correos (si es que ha brindado alguno) y los teléfonos (si es que ha brindado alguno). Ordenar el
resultado con respecto al id del cliente en orden ascendente.*/

SELECT C.id, C.nombre,  C.direccion, TP.tipo, TC.telefono , CC.correo
FROM CLIENTE C
LEFT JOIN TELEFONO_CLIENTE TC
    ON TC.id_cliente = C.id
LEFT JOIN CORREO_CLIENTE CC
    ON CC.id_cliente = C.id
LEFT JOIN TIPO_PLAN TP
    ON TP.id = C.id_tipo_plan
ORDER BY C.id ASC

/*4. Identificar las consultas que han necesitado de un médico asistente, mostrar el id de la consulta, la
fecha, la duración, el id del médico y el nombre del médico asistente. Ordenar el resultado con
respecto al id de la consulta en orden ascendente.*/

SELECT C.id 'id_consulta', C.fecha, C.duracion, M.id 'id_medico', M.nombre 'medico_asistente'
FROM CONSULTA C
INNER JOIN MEDICOXCONSULTA MC
    ON MC.id_consulta = C.id
INNER JOIN MEDICO M
    ON M.id = MC.id_medico
WHERE MC.rol LIKE '0'
ORDER BY C.id ASC


/*5. ¿Cuáles son las clínicas capacitadas para atender emergencias? Mostrar el id de la clínica, el nombre,
la dirección y email.*/

SELECT C.id, C.nombre, C.direccion, C.email
FROM CLINICA C
INNER JOIN EMERGENCIA E
    ON E.id_clinica = C.id
GROUP BY C.id, C.nombre, C.direccion, C.email

/*6. Calcular las ganancias de la asociación en la primera quincena de mayo. Mostrar la fecha de la
consulta, el nombre del cliente atendido y el nombre del médico principal. Se debe considerar que
existe la posibilidad de que haya consultas en las que no se recete ningún medicamento. Ordenar el
resultado con respecto al id de la consulta en orden ascendente. Las ganancias de cada consulta se
calculan de la siguiente forma: (Precio de la consulta + Suma de todos los medicamentos recetados) +
13% IVA.*/

SELECT C.id 'id_consulta', C.fecha 'fecha', CL.nombre 'nombre_cliente', M.nombre 'nombre_medico', SUM(MD.precio) 'subtotal_medicamento' , C.precio 'precio_consulta', (SUM(MD.precio) + C.precio) * 1.13 'total_consulta'
FROM CONSULTA C
LEFT JOIN CLIENTE CL
    ON C.id_cliente = CL.id
LEFT JOIN RECETA R
    ON R.id_consulta = C.id
LEFT JOIN MEDICAMENTO MD
    ON R.id_medicamento = MD.id
LEFT JOIN MEDICOXCONSULTA MC
    ON MC.id_consulta = C.id
LEFT JOIN MEDICO M
    ON M.id = MC.id_medico
WHERE mc.rol LIKE 1 AND C.fecha BETWEEN '2022-05-01' AND '2022-05-15'
GROUP BY C.id,C.fecha, CL.nombre, M.nombre, C.precio
ORDER BY C.id ASC;

/*7. El comité de dirección planea realizar una fuerte inversión con el objetivo de establecer a la asociación
como el consorcio líder a nivel nacional, para verificar la viabilidad del proyecto, el comité ha solicitado
un reporte especial que consiste en mostrar las ganancias del mes de mayo de 2022 pero
organizadas en base a 4 grupos de fechas.*/

SELECT  
        CASE WHEN C.fecha BETWEEN '20220501 00:00' AND '20220508 23:59' THEN 'Semana 1'
            WHEN C.fecha BETWEEN '20220509 00:00' AND '20220515 23:59' THEN 'Semana 2'
            WHEN C.fecha BETWEEN '20220516 00:00' AND '20220522 23:59' THEN 'Semana 3'
            WHEN C.fecha BETWEEN '20220523 00:00' AND '20220531 23:59' THEN 'Semana 4' END AS 'semana',
                
        ROUND((SUM(CASE WHEN C.fecha BETWEEN '20220501 00:00' AND '20220508 23:59' THEN C.precio
                        WHEN C.fecha BETWEEN '20220509 00:00' AND '20220515 23:59' THEN C.precio
                        WHEN C.fecha BETWEEN '20220516 00:00' AND '20220522 23:59' THEN C.precio
                        WHEN C.fecha BETWEEN '20220523 00:00' AND '20220531 23:59' THEN C.precio END)+MED.[MEDIC PRECIO])+0.13,2) 'GANANCIA'

FROM(
    SELECT CASE WHEN C.fecha BETWEEN '20220501 00:00' AND '20220508 23:59' THEN 'Semana 1'
                WHEN C.fecha BETWEEN '20220509 00:00' AND '20220515 23:59' THEN 'Semana 2'
                WHEN C.fecha BETWEEN '20220516 00:00' AND '20220522 23:59' THEN 'Semana 3'
                WHEN C.fecha BETWEEN '20220523 00:00' AND '20220531 23:59' THEN 'Semana 4' END AS SEMANA,
                SUM (M.precio) 'MEDIC PRECIO'
    FROM CONSULTA C, MEDICAMENTO M, RECETA R
    WHERE C.id = R.id_consulta AND M.id = R.id_medicamento
    GROUP BY CASE 
                WHEN C.fecha BETWEEN '20220501 00:00' AND '20220508 23:59' THEN 'Semana 1'
                WHEN C.fecha BETWEEN '20220509 00:00' AND '20220515 23:59' THEN 'Semana 2'
                WHEN C.fecha BETWEEN '20220516 00:00' AND '20220522 23:59' THEN 'Semana 3'
                WHEN C.fecha BETWEEN '20220523 00:00' AND '20220531 23:59' THEN 'Semana 4' END
    ) MED, CONSULTA C

WHERE MED.SEMANA LIKE CASE WHEN C.fecha BETWEEN '20220501 00:00' AND '20220508 23:59' THEN 'Semana 1'
                            WHEN C.fecha BETWEEN '20220509 00:00' AND '20220515 23:59' THEN 'Semana 2'
                            WHEN C.fecha BETWEEN '20220516 00:00' AND '20220522 23:59' THEN 'Semana 3'
                            WHEN C.fecha BETWEEN '20220523 00:00' AND '20220531 23:59' THEN 'Semana 4' END 
                            
GROUP BY MED.[MEDIC PRECIO],CASE WHEN C.fecha BETWEEN '20220501 00:00' AND '20220508 23:59' THEN 'Semana 1'
                                WHEN C.fecha BETWEEN '20220509 00:00' AND '20220515 23:59' THEN 'Semana 2'
                                WHEN C.fecha BETWEEN '20220516 00:00' AND '20220522 23:59' THEN 'Semana 3'
                                WHEN C.fecha BETWEEN '20220523 00:00' AND '20220531 23:59' THEN 'Semana 4' END