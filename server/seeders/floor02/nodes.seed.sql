INSERT INTO nodes (type, floor, px, py, code, label, isLandmark) VALUES
-- Baños Floor 2 (Verde)
(6, 2, 497.0, 220.0, 'BATH-F2', 'Baños', 1),

-- Zona Chilling (Amarillo)
(13, 2, 479.0, 190.0, 'SECU-F2', 'Cuarto Servidores', 1),

-- Aulas 309 a 307 y Auditorio (Rojo)
(1, 2, 369.0, 247.0, 'R-309-F2', 'Aula 309', 1),
(1, 2, 404.0, 247.0, 'R-308-F2', 'Aula 308', 1),
(1, 2, 437.0, 247.0, 'R-307-F2', 'Aula 307', 1),
(12, 2, 590.0, 247.0, 'AUDITORIO-F2', 'Auditorio', 1),

-- ========================================================

-- Elevator - Edificio  (Morado)
(5, 2, 526.0, 190.0, 'EL-EDI-F2', 'Elevador F2', 0),

-- Stairs Izquierda - Arriba F3 y Abajo F1 (Morado)
(3, 2, 365.0, 185.0, 'ST-L1-UP-F3', 'Escalera F2-F3', 0),
(4, 2, 389.0, 185.0, 'ST-L2-DOWN-F1', 'Escalera F2-F1', 0),

-- Stairs Derecha - Arriba F3 y Abajo F1 (Morado)
(3, 2, 606.0, 185.0, 'ST-R1-UP-F3', 'Escalera F2-F3', 0),
(4, 2, 632.0, 185.0, 'ST-R2-DOWN-F1', 'Escalera F2-F1', 0),

-- ========================================================

-- Waypoints - Eje Horizontal, Izquierda Edificio (3 puntos)
(0, 2, 437.0, 220.0, 'WP-F2-27', '', 0),
(0, 2, 402.0, 220.0, 'WP-F2-28', '', 0),
(0, 2, 368.0, 220.0, 'WP-F2-29', '', 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (3 puntos)
(0, 2, 556.0, 220.0, 'WP-F2-30', '', 0),
(0, 2, 590.0, 220.0, 'WP-F2-31', '', 0),
(0, 2, 624.0, 220.0, 'WP-F2-32', '', 0);
