/*Ejercicio 1. Los clientes VIP tienen acceso a una serie de servicios adicionales en los distintos aeropuertos que visitan, 
por lo que se solicita que defina la lista de clientes VIP. El criterio de evaluación consiste en verificar que el promedio 
de las reservas realizadas por un cliente sea mayor a 1799.00. En la evaluación se debe tener en cuenta todos los servicios 
extra que incluyan los clientes en las reservas. Restricción : El ejercicio debe realizarse en una consulta SELECT, sin 
utilizar la sentencia INTO, tablas temporales o bloques de programación (bloques anónimos, funciones o procedimientos almacenados). 
Resultado esperado:*/

SELECT P.id, P.nombre, R.
FROM PASAJERO P
INNER JOIN RESERVA R
    ON R.id_pasajero = P.id


/*Ejercicio 2. Cada reserva tiene una fecha en la que fue realizada, una solicitud del departamento de finanzas del consorcio requiere 
la ganancia del mes de abril de 2021, pero los datos deben estar organizados por días. Como parte de la solicitud, se requiere que la fecha 
sea mostrada en un formato especial (ver imagen de vista esperada). Para calcular el valor de una reserva se debe tomar en cuenta tanto el precio 
de la reserva como la suma de todos los servicios extras incluidos. Restricción : El ejercicio debe realizarse en una consulta SELECT, sin utilizar 
la sentencia INTO, tablas temporales o bloques de programación (bloques anónimos, funciones o procedimientos almacenados). Sugerencia : Investigar 
sobre la instrucción CONVERT y su utilización en la instrucción SELECT. Sección del resultado esperado (El resultado contiene más filas)*/

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