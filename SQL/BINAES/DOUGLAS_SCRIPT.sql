-- Disponiblididad caundo no retorne nada esta query
SELECT *
FROM BOOK_LOAN bl
WHERE bl.loan_timestamp IS NOT NULL AND bl.return_timestamp IS NULL;

id_reserva: 5678
id_user: 00133121
id_book: TLOTR_1_45
timestamp: 2022-05-17 17:35 -06:00
did_user_come: NULL 
expected_loan_timestamp: 2022-05-18 06:00 -06:00
expected_return_timestamp: 2022-05-31 15:30 -06:00 
loan_timestamp: 2022-05-18 06:00 -06:00
return_timestamp: 2022-05-20 17:30 -06:00

-- Usuario realiza la reserva
id_reserva: 5678
id_user: 00133121
id_book: TLOTR_1_45
timestamp: 2022-05-17 17:35 -06:00 
did_user_come: false
expected_loan_timestamp: 2022-05-18 06:00 -06:00
expected_return_timestamp: NULL 
loan_timestamp: NULL
return_timestamp: NULL

-- Usuario realiza la reserva y no llega
id_reserva: 5678
id_user: 00133121
id_book: TLOTR_1_45
did_user_come: false
timestamp: 2022-05-17 17:35 -06:00 
expected_loan_timestamp: 2022-05-18 06:00 -06:00
expected_return_timestamp: NULL 
loan_timestamp: NULL
return_timestamp: NULL

-- Usuario presta libro
id_reserva: 5678
id_user: 00133121
id_book: TLOTR_1_45
timestamp: 2022-05-17 17:35 -06:00 
did_user_come: true
expected_loan_timestamp: 2022-05-18 06:00 -06:00
expected_return_timestamp: 2022-05-31 15:30 -06:00 
loan_timestamp: 2022-05-18 06:00 -06:00
return_timestamp: NULL

-- Usuario Devuelve Libro
id_reserva: 5678
id_user: 00133121
id_book: TLOTR_1_45
timestamp: 2022-05-17 17:35 -06:00 
did_user_come: true
expected_loan_timestamp: 2022-05-18 06:00 -06:00
expected_return_timestamp: 2022-05-31 15:30 -06:00 
loan_timestamp: 2022-05-18 06:00 -06:00
return_timestamp: 2022-05-20 17:30 -06:00