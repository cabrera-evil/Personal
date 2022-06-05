--EJERCICIO 01: Mostrar la lista de platos ordenada de forma descendente con respecto a su precio
SELECT * 
FROM PLATO P
ORDER BY P.precio DESC;

--EJERCICIO 02: Mostrar aquellos restaurantes cuya direccion empieza por un digito
SELECT * 
FROM RESTAURANTE R
WHERE R.direccion LIKE '[0-9]%';

--EJERCICIO 03: Mostrar todos los lcientes con el correo terminado con ".org"
SELECT *
FROM CLIENTE C
WHERE C.correo LIKE '%.org';

--EJERCICIO 04: Mostrar las facturas que se encuentran entre febrero y marzo del 2022
SELECT *
FROM FACTURA F
WHERE F.fecha LIKE '2022-02-%' OR F.fecha LIKE '2022-03-%'
ORDER BY F.fecha;

--EJERCICIO 05: Mostrar la cantidad de ingredientes de los platos cuyo precio es superior a los 5 USD. Se deben de ostrar del mas economico al mas caro
SELECT P.nombre 'Nombre de plato', P.precio 'Precio de plato', COUNT(I.id) 'Cant. Ingrediente'
FROM INGREDIENTE I
INNER JOIN PLATOXINGREDIENTE PD
    ON PD.id_ingrediente = I.id
INNER JOIN PLATO P
    ON P.id = PD.id_plato
WHERE P.precio > '8'
GROUP BY P.nombre, P.precio
ORDER BY P.precio ASC;

--EJERCICIO 06: Mostrar la lista de postres en orden de popularidad. Esta metrica depende del numero de postres registrados como vendidos
SELECT P.nombre 'Postre', P.precio 'Precio', COUNT(DP.id_postre) 'Cantidad de ventas'
FROM POSTRE P
INNER JOIN DETALLE_POSTRE DP
    ON DP.id_postre = P.id
INNER JOIN FACTURA F
    ON F.id = DP.id_factura
GROUP BY P.nombre, P.precio
ORDER BY 'Cantidad de ventas' DESC;

--EJERCICIO 07: Mostrar los platos destinados al menu de "invierno". Ordenar los resultados del mas caro al mas economico
SELECT P.nombre "Plato", P.precio 'Precio', M.estacion 'Estacion'
FROM MENU M
INNER JOIN PLATO P
    ON P.id_menu = M.id
WHERE M.estacion LIKE 'invierno'
ORDER BY P.precio DESC;

--EJERCICIO 08: Liste los postres que ha comprado el cliente con el nombre "Clementine CLarke". Ordenarlos del mas reciente al mas antiguo.
SELECT F.id 'Fact. #', F.fecha 'Fecha de compra', C.nombre 'Cliente', P.nombre 'Postre'
FROM POSTRE P
LEFT JOIN DETALLE_POSTRE DP
    ON DP.id_postre = P.id
LEFT JOIN FACTURA F
    ON F.id = DP.id_factura
LEFT JOIN CLIENTE C
    ON C.id = F.id_cliente
WHERE C.nombre LIKE 'Clementine Clarke'
ORDER BY F.fecha DESC;

--EJERCICIO 09: Mostrar la cantidad de platos existentes en cada menu. Ordenar el resultado a partir de esta metrica, de mayor a menor
SELECT M.nombre 'Menu', M.estacion 'Estación', COUNT(P.id_menu) 'Cantidad de platos'
FROM MENU M
INNER JOIN PLATO P
    ON P.id_menu = M.id
GROUP BY M.nombre, M.estacion
ORDER BY 'Cantidad de platos';

--EJERCICIO 10: Mostrar el subtotal de postres presentes en las facturas, indicando: id de factura, restaurante, nombre del cliente, subtotal de postres
SELECT f.id 'Fact. #', R.nombre 'Restaurante', C.nombre 'Cliente', ROUND(SUM(P.precio),2) 'Subtotal Postres'
FROM POSTRE P
INNER JOIN DETALLE_POSTRE DP
    ON DP.id_postre = P.id
INNER JOIN FACTURA F
    ON F.id = DP.id_factura
INNER JOIN CLIENTE C
    ON C.id = F.id_cliente
INNER JOIN RESTAURANTE R
    ON R.id = F.id_restaurante
GROUP BY F.id, R.nombre, C.nombre
ORDER BY F.id;