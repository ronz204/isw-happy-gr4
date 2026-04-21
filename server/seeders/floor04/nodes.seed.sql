INSERT INTO nodes (type, floor, px, py, code, label, isLandmark, landmarkLvl) VALUES
-- Baños (Verdes)
(7, 4, 0.0, 0.0, 'WC-M-F4', 'Baño Hombres', 1, 1),
(6, 4, 0.0, 0.0, 'WC-F-F4', 'Baño Mujeres', 1, 1),

-- Servicios y Puntos Clave (Amarillos)
(11, 4, 0.0, 0.0, 'DIN-F4', 'Comedor Central', 1, 2),
(8, 4, 0.0, 0.0, 'SEC-F4', 'Seguridad', 1, 2),

-- Aulas (Rojos con número)
(1, 4, 0.0, 0.0, 'R-316', 'Aula 316', 0, 0),
(1, 4, 0.0, 0.0, 'R-317', 'Aula 317', 0, 0),
(1, 4, 0.0, 0.0, 'R-318', 'Aula 318', 0, 0),

-- Oficinas (Rojos sin número - Lado derecho)
(2, 4, 0.0, 0.0, 'OFF-F4-D1', 'Oficina D1', 0, 0),
(2, 4, 0.0, 0.0, 'OFF-F4-D2', 'Oficina D2', 0, 0),
(2, 4, 0.0, 0.0, 'OFF-F4-D3', 'Oficina D3', 0, 0),

-- Conectividad Vertical Edifico (Rosados - Escaleras)
(3, 4, 0.0, 0.0, 'ST-L1-UP-F5', 'Escalera F4-F5', 0, 0),
(4, 4, 0.0, 0.0, 'ST-L2-DOWN-F3', 'Escalera F4-F3', 0, 0),
(4, 4, 0.0, 0.0, 'ST-R1-DOWN-F3', 'Escalera F4-F3', 0, 0),
(3, 4, 0.0, 0.0, 'ST-R2-UP-F5', 'Escalera F4-F5', 0, 0),

-- Conectividad Vertical Elevadores (Rosados - Ascensores)
(5, 4, 0.0, 0.0, 'EL-L1-EDI-F4', 'Elevador #1', 0, 0),
(5, 4, 0.0, 0.0, 'EL-R1-EDI-F4', 'Elevador #2', 0, 0),

-- Conectividad Vertical Comedor - Biblioteca (Rosados - Escaleras/Ascensores)
(4, 4, 0.0, 0.0, 'ST-DOWN-LIBRARY', 'Escalera Biblioteca', 0, 0),
(5, 4, 0.0, 0.0, 'EL-C1-CAF-F4', 'Elevador #3', 0, 0),

-- Waypoints - Comedor (3 puntos)
(0, 4, 0.0, 0.0, 'WP-F4-01', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-02', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-03', '', 0, 0),

-- Waypoints - Eje Vertical de Comedor a Parqueo (4 puntos)
(0, 4, 0.0, 0.0, 'WP-F4-04', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-05', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-06', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-07', '', 0, 0),

-- Waypoints - Parqueo (6 puntos)
(12, 4, 0.0, 0.0, 'WP-F4-08', '', 0, 0),
(12, 4, 0.0, 0.0, 'WP-F4-09', '', 0, 0),
(12, 4, 0.0, 0.0, 'WP-F4-10', '', 0, 0),
(12, 4, 0.0, 0.0, 'WP-F4-11', '', 0, 0),
(12, 4, 0.0, 0.0, 'WP-F4-12', '', 0, 0),
(12, 4, 0.0, 0.0, 'WP-F4-13', '', 0, 0),

-- Waypoints - Puente a Comedor y Pasillo Principal (10 puntos)
(0, 4, 0.0, 0.0, 'WP-F4-14', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-15', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-16', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-17', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-18', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-19', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-20', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-21', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-22', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-23', '', 0, 0),

-- Waypoint - Puente del Parqueo a la Entrada (4 Puntos)
(0, 4, 0.0, 0.0, 'WP-F4-24', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-25', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-26', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-27', '', 0, 0),

-- Waypoints - Entrada y Pasillo de Acceso (3 puntos)
(0, 4, 0.0, 0.0, 'WP-F4-28', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-29', '', 0, 0),
(0, 4, 0.0, 0.0, 'WP-F4-30', '', 0, 0);
