INSERT INTO nodes (type, floor, px, py, code, label, isLandmark) VALUES
-- Baños Comedor (Verde)
(6, 4, 175.0, 338.0, 'BATH-F4', 'Baños', 1),

-- Soda Comedor (Amarillo)
(10, 4, 322.0, 338.0, 'CAFE-F4', 'Soda Comedor', 1),

-- Entrada Principal (Amarillo)
(8, 4, 932.0, 577.0, 'ENTR-F4', 'Entrada Principal', 1),

-- Parqueo Superior (Amarillo)
(11, 4, 446.0, 577.0, 'PARK-F4', 'Parqueo Superior', 1),

-- Oficinas de Seguridad (Amarillo)
(13, 4, 893.0, 331.0, 'SECU-F4', 'Oficinas de Guardas', 1),

-- Aulas 316 a 318 (Rojo)
(1, 4, 693.0, 456.0, 'R-316-F4', 'Aula 316', 1),
(1, 4, 755.0, 456.0, 'R-317-F4', 'Aula 317', 1),
(1, 4, 818.0, 456.0, 'R-318-F4', 'Aula 318', 1),

-- Oficinas D1 a D3 (Rojo)
(2, 4, 1042.0, 456.0, 'OFF-F4-D1', 'Oficina D1', 1),
(2, 4, 1109.0, 456.0, 'OFF-F4-D2', 'Oficina D2', 1),
(2, 4, 1175.0, 456.0, 'OFF-F4-D3', 'Oficina D3', 1),

-- ========================================================

-- Elevator - Edificio & Biblioteca (Morado)
(5, 4, 986.0, 345.0, 'EL-EDI-F4', 'Elevador F4', 0),
(5, 4, 514.0, 335.0, 'EL-CAF-F4', 'Elevador Biblioteca', 0),

-- Stairs Izquierda - Arriba F5 y Abajo F3 (Morado)
(3, 4, 684.0, 346.0, 'ST-L1-UP-F5', 'Escalera F4-F5', 0),
(4, 4, 730.0, 346.0, 'ST-L2-DOWN-F3', 'Escalera F4-F3', 0),

-- Stairs Derecha - Arriba F5 y Abajo F3 (Morado)
(3, 4, 1136.0, 346.0, 'ST-R1-UP-F5', 'Escalera F4-F5', 0),
(4, 4, 1184.0, 346.0, 'ST-R2-DOWN-F3', 'Escalera F4-F3', 0),

-- ========================================================

-- Waypoints - Eje Vertical, Entrada a Edificio (4 puntos)
(0, 4, 930.0, 514.0, 'WP-F4-01', '', 0),
(0, 4, 930.0, 475.0, 'WP-F4-02', '', 0),
(0, 4, 930.0, 440.0, 'WP-F4-03', '', 0),
(0, 4, 930.0, 394.0, 'WP-F4-04', '', 0),

-- Waypoints - Eje Horizontal, Entrada a Parqueo (8 Puntos)
(0, 4, 881.0, 577.0, 'WP-F4-05', '', 0),
(0, 4, 815.0, 577.0, 'WP-F4-06', '', 0),
(0, 4, 760.0, 577.0, 'WP-F4-07', '', 0),
(0, 4, 713.0, 577.0, 'WP-F4-08', '', 0),
(0, 4, 660.0, 577.0, 'WP-F4-09', '', 0),
(0, 4, 606.0, 577.0, 'WP-F4-10', '', 0),
(0, 4, 546.0, 577.0, 'WP-F4-11', '', 0),
(0, 4, 491.0, 577.0, 'WP-F4-12', '', 0),

-- Waypoints - Eje Vertical, Parqueo a Comedor (5 Puntos)
(0, 4, 446.0, 536.0, 'WP-F4-13', '', 0),
(0, 4, 466.0, 485.0, 'WP-F4-14', '', 0),
(0, 4, 466.0, 432.0, 'WP-F4-15', '', 0),
(0, 4, 466.0, 394.0, 'WP-F4-16', '', 0),
(0, 4, 466.0, 334.0, 'WP-F4-17', '', 0),

-- Waypoints - Eje Horizontal, Izquierda Edificio (4 puntos)
(0, 4, 884.0, 394.0, 'WP-F4-18', '', 0),
(0, 4, 821.0, 394.0, 'WP-F4-19', '', 0),
(0, 4, 754.0, 394.0, 'WP-F4-20', '', 0),
(0, 4, 687.0, 394.0, 'WP-F4-21', '', 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (4 puntos)
(0, 4, 984.0, 394.0, 'WP-F4-22', '', 0),
(0, 4, 1041.0, 394.0, 'WP-F4-23', '', 0),
(0, 4, 1109.0, 394.0, 'WP-F4-24', '', 0),
(0, 4, 1174.0, 394.0, 'WP-F4-25', '', 0),

-- Waypoints - Eje Horizontal, Puente a Comedor (3 puntos)
(0, 4, 614.0, 394.0, 'WP-F4-26', '', 0),
(0, 4, 557.0, 394.0, 'WP-F4-27', '', 0),
(0, 4, 504.0, 394.0, 'WP-F4-28', '', 0);
