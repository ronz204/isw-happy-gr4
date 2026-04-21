INSERT INTO nodes (type, floor, px, py, code, label, isLandmark, landmarkLvl) VALUES
-- Entrada Principal (Amarillo)
(8, 4, 993.0, 619.0, 'ENTR-F4', 'Entrada Principal', 1, 1),
-- Parqueo Superior (Amarillo)
(11, 4, 479.0, 616.0, 'PARK-F4', 'Parqueo Superior', 1, 1),
-- Oficinas de Seguridad (Amarillo)
(13, 4, 995.0, 362.0, 'SECU-F4', 'Oficinas de Seguridad', 1, 1),
-- Soda Comedor (Amarillo)
(10, 4, 328.0, 362.0, 'CAFE-F4', 'Soda Comedor', 1, 1),

-- Aulas 316 a 318 (Rojo)
(1, 4, 737.0, 490.0, 'R-316', 'Aula 316', 0, 0),
(1, 4, 807.0, 490.0, 'R-317', 'Aula 317', 0, 0),
(1, 4, 876.0, 490.0, 'R-318', 'Aula 318', 0, 0),

-- Oficinas D1 a D3 (Rojo)
(2, 4, 1113.0, 490.0, 'OFF-F4-D1', 'Oficina D1', 0, 0),
(2, 4, 1184.0, 490.0, 'OFF-F4-D2', 'Oficina D2', 0, 0),
(2, 4, 1255.0, 490.0, 'OFF-F4-D3', 'Oficina D3', 0, 0),

-- Baños Comedor (Verde)
(6, 4, 189.0, 362.0, 'BATH-F4', 'Baños', 1, 1),

-- Elevator - Edificio (Morado)
(5, 4, 1053.0, 379.0, 'EL-EDI-F4', 'Elevador F4', 0, 0),

-- Waypoints - Eje Vertical, Entrada a Edificio (4 puntos)
(0, 4, 993.0, 555.0, 'WP-F4-01', '', 0, 0),
(0, 4, 933.0, 503.0, 'WP-F4-02', '', 0, 0),
(0, 4, 933.0, 460.0, 'WP-F4-03', '', 0, 0),
(0, 4, 933.0, 420.0, 'WP-F4-04', '', 0, 0),

-- Waypoints - Eje Horizontal, Entrada a Parqueo (8 Puntos)
(0, 4, 940.0, 619.0, 'WP-F4-05', '', 0, 0),
(0, 4, 860.0, 619.0, 'WP-F4-06', '', 0, 0),
(0, 4, 822.0, 619.0, 'WP-F4-07', '', 0, 0),
(0, 4, 772.0, 619.0, 'WP-F4-08', '', 0, 0),
(0, 4, 716.0, 619.0, 'WP-F4-09', '', 0, 0),
(0, 4, 654.0, 619.0, 'WP-F4-10', '', 0, 0),
(0, 4, 592.0, 619.0, 'WP-F4-11', '', 0, 0),
(0, 4, 535.0, 619.0, 'WP-F4-12', '', 0, 0),

-- Waypoints - Eje Vertical, Parqueo a Comedor (4 Puntos)
(0, 4, 479.0, 563.0, 'WP-F4-13', '', 0, 0),
(0, 4, 479.0, 515.0, 'WP-F4-14', '', 0, 0),
(0, 4, 479.0, 466.0, 'WP-F4-15', '', 0, 0),
(0, 4, 479.0, 418.0, 'WP-F4-16', '', 0, 0),

-- Waypoints - Eje Horizontal, Izquierda Edificio (4 puntos)
(0, 4, 946.0, 420.0, 'WP-F4-17', '', 0, 0),
(0, 4, 874.0, 420.0, 'WP-F4-18', '', 0, 0),
(0, 4, 805.0, 420.0, 'WP-F4-19', '', 0, 0),
(0, 4, 735.0, 420.0, 'WP-F4-20', '', 0, 0),

-- Stairs Izquierda - Arriba F5 y Abajo F3 (Morado)
(3, 4, 729.0, 374.0, 'ST-L1-UP-F5', 'Escalera F4-F5', 0, 0),
(4, 4, 778.0, 374.0, 'ST-L2-DOWN-F3', 'Escalera F4-F3', 0, 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (4 puntos)
(0, 4, 1050.0, 420.0, 'WP-F4-21', '', 0, 0),
(0, 4, 1112.0, 420.0, 'WP-F4-22', '', 0, 0),
(0, 4, 1184.0, 420.0, 'WP-F4-23', '', 0, 0),
(0, 4, 1250.0, 420.0, 'WP-F4-24', '', 0, 0),

-- Stairs Derecha - Arriba F5 y Abajo F3 (Morado)
(3, 4, 1213.0, 374.0, 'ST-R1-UP-F5', 'Escalera F4-F5', 0, 0),
(4, 4, 1262.0, 374.0, 'ST-R2-DOWN-F3', 'Escalera F4-F3', 0, 0),

-- Waypoints - Eje Horizontal, Puente a Comedor (3 puntos)
(0, 4, 658.0, 420.0, 'WP-F4-25', '', 0, 0),
(0, 4, 592.0, 420.0, 'WP-F4-26', '', 0, 0),
(0, 4, 545.0, 420.0, 'WP-F4-27', '', 0, 0),

-- Stairs y Elevator - Comedor a Biblioteca (Morado)
(4, 4, 596.0, 364.0, 'ST-CAF-DOWN-LIB', 'Escalera Biblioteca', 0, 0),
(5, 4, 549.0, 364.0, 'EL-CAF-F4', 'Elevador Biblioteca', 0, 0),

-- Waypoints - Pasillo Comedor (1 puntos)
(0, 4, 483.0, 362.0, 'WP-F4-28', '', 0, 0);