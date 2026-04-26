INSERT INTO nodes (type, floor, px, py, code, label, isLandmark) VALUES
-- Baños Comedor (Verde)
(6, 4, 93.0, 186.0, 'BATH-F4', 'Baños', 1),

-- Soda Comedor (Amarillo)
(10, 4, 172.0, 186.0, 'CAFE-F4', 'Soda Comedor', 1),

-- Entrada Principal (Amarillo)
(8, 4, 497.0, 317.0, 'ENTR-F4', 'Entrada Principal', 1),

-- Parqueo Superior (Amarillo)
(11, 4, 241.0, 317.0, 'PARK-F4', 'Parqueo Superior', 1),

-- Oficinas de Seguridad (Amarillo)
(13, 4, 479.0, 190.0, 'SECU-F4', 'Oficinas de Guardas', 1),

-- Aulas 316 a 318 (Rojo)
(1, 4, 369.0, 247.0, 'R-316-F4', 'Aula 316', 1),
(1, 4, 404.0, 247.0, 'R-317-F4', 'Aula 317', 1),
(1, 4, 437.0, 247.0, 'R-318-F4', 'Aula 318', 1),

-- Oficinas D1 a D3 (Rojo)
(2, 4, 558.0, 247.0, 'OFF-F4-D1', 'Oficina D1', 1),
(2, 4, 592.0, 247.0, 'OFF-F4-D2', 'Oficina D2', 1),
(2, 4, 627.0, 247.0, 'OFF-F4-D3', 'Oficina D3', 1),

-- ========================================================

-- Elevator - Edificio & Biblioteca (Morado)
(5, 4, 526.0, 190.0, 'EL-EDI-F4', 'Elevador F4', 0),
(5, 4, 274.0, 185.0, 'EL-CAF-F4', 'Elevador Biblioteca', 0),
(5, 4, 297.0, 185.0, 'ST-CAF-F4', 'Escalera Biblioteca', 0),

-- Stairs Izquierda - Arriba F5 y Abajo F3 (Morado)
(3, 4, 365.0, 185.0, 'ST-L1-UP-F5', 'Escalera F4-F5', 0),
(4, 4, 389.0, 185.0, 'ST-L2-DOWN-F3', 'Escalera F4-F3', 0),

-- Stairs Derecha - Arriba F5 y Abajo F3 (Morado)
(3, 4, 606.0, 185.0, 'ST-R1-UP-F5', 'Escalera F4-F5', 0),
(4, 4, 632.0, 185.0, 'ST-R2-DOWN-F3', 'Escalera F4-F3', 0),

-- ========================================================

-- Waypoints - Eje Vertical, Entrada a Edificio (3 puntos)
(0, 4, 497.0, 280.0, 'WP-F4-01', '', 0),
(0, 4, 497.0, 250.0, 'WP-F4-02', '', 0),
(0, 4, 497.0, 220.0, 'WP-F4-03', '', 0),

-- Waypoints - Eje Horizontal, Entrada a Parqueo (5 Puntos)
(0, 4, 440.0, 317.0, 'WP-F4-04', '', 0),
(0, 4, 404.0, 317.0, 'WP-F4-05', '', 0),
(0, 4, 368.0, 317.0, 'WP-F4-06', '', 0),
(0, 4, 330.0, 317.0, 'WP-F4-07', '', 0),
(0, 4, 290.0, 317.0, 'WP-F4-08', '', 0),

-- Waypoints - Eje Vertical, Parqueo a Comedor (4 Puntos)
(0, 4, 241.0, 284.0, 'WP-F4-09', '', 0),
(0, 4, 241.0, 257.0, 'WP-F4-10', '', 0),
(0, 4, 241.0, 220.0, 'WP-F4-11', '', 0),
(0, 4, 241.0, 186.0, 'WP-F4-12', '', 0),

-- Waypoints - Eje Horizontal, Izquierda Edificio (3 puntos)
(0, 4, 437.0, 220.0, 'WP-F4-13', '', 0),
(0, 4, 402.0, 220.0, 'WP-F4-14', '', 0),
(0, 4, 368.0, 220.0, 'WP-F4-15', '', 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (3 puntos)
(0, 4, 556.0, 220.0, 'WP-F4-16', '', 0),
(0, 4, 590.0, 220.0, 'WP-F4-17', '', 0),
(0, 4, 624.0, 220.0, 'WP-F4-18', '', 0),

-- Waypoints - Eje Horizontal, Puente a Comedor (2 puntos)
(0, 4, 328.0, 220.0, 'WP-F4-19', '', 0),
(0, 4, 287.0, 220.0, 'WP-F4-20', '', 0);
