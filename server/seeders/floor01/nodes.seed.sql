INSERT INTO nodes (type, floor, px, py, code, label, isLandmark) VALUES
-- Biblioteca Floor 1 (Verde)
(9, 1, 251.0, 155.0, 'LIBRARY-F1', 'Biblioteca F1', 1),
(6, 1, 84.0, 155.0, 'BATH-F1-LIB', 'Biblioteca Baños', 1),

-- Ping Pong Floor 1 (Verde)
(7, 1, 497.0, 220.0, 'PING-PONG-F1', 'Ping Pong', 1),

-- Zona Chilling (Amarillo)
(7, 1, 480.0, 251.0, 'CHILL-F1', 'Zona Libre F1', 1),

-- Aulas 310 a 315 y Auditorio (Rojo)
(1, 1, 369.0, 194.0, 'R-306-F1', 'Aula 306', 1),
(1, 1, 404.0, 194.0, 'R-305-F1', 'Aula 305', 1),
(1, 1, 437.0, 194.0, 'R-304-F1', 'Aula 304', 1),
(1, 1, 558.0, 194.0, 'R-303-F1', 'Aula 303', 1),
(1, 1, 592.0, 194.0, 'R-302-F1', 'Aula 302', 1),
(1, 1, 627.0, 194.0, 'R-301-F1', 'Aula 301', 1),

-- ========================================================

-- Elevator - Edificio  (Morado)
(5, 1, 526.0, 251.0, 'EL-EDI-F1', 'Elevador F1', 0),
(5, 1, 274.0, 186.0, 'EL-LIB-F1', 'Elevador Biblioteca', 0),
(5, 1, 277.0, 162.0, 'ST-LIB-F1', 'Escalera Biblioteca', 0),

-- Stairs Izquierda - Arriba F2  (Morado)
(3, 1, 370.0, 256.0, 'ST-L1-UP-F2', 'Escalera F1-F2', 0),

-- Stairs Derecha - Arriba F2 (Morado)
(4, 1, 625.0, 256.0, 'ST-R1-UP-F2', 'Escalera F1-F2', 0),

-- ========================================================

-- Waypoints - Eje Horizontal, Izquierda Edificio (3 puntos)
(0, 1, 437.0, 220.0, 'WP-F1-39', '', 0),
(0, 1, 404.0, 220.0, 'WP-F1-40', '', 0),
(0, 1, 369.0, 220.0, 'WP-F1-41', '', 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (3 puntos)
(0, 1, 558.0, 220.0, 'WP-F1-42', '', 0),
(0, 1, 592.0, 220.0, 'WP-F1-43', '', 0),
(0, 1, 627.0, 220.0, 'WP-F1-44', '', 0);
