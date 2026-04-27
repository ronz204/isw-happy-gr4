INSERT INTO nodes (type, floor, px, py, code, label, isLandmark) VALUES
-- Baños Floor 3 (Verde)
(6, 3, 497.0, 220.0, 'BATH-F3', 'Baños', 1),

-- Zona Chilling (Amarillo)
(13, 3, 480.0, 251.0, 'CHILL-F3', 'Zona Libre F3', 1),

-- Aulas 310 a 315 y Auditorio (Rojo)
(1, 3, 369.0, 194.0, 'R-310-F3', 'Aula 310', 1),
(1, 3, 404.0, 194.0, 'R-311-F3', 'Aula 311', 1),
(1, 3, 437.0, 194.0, 'R-312-F3', 'Aula 312', 1),
(1, 3, 558.0, 194.0, 'R-313-F3', 'Aula 313', 1),
(1, 3, 592.0, 194.0, 'R-314-F3', 'Aula 314', 1),
(1, 3, 627.0, 194.0, 'R-315-F3', 'Aula 315', 1),

-- ========================================================

-- Elevator - Edificio  (Morado)
(5, 3, 526.0, 251.0, 'EL-EDI-F3', 'Elevador F3', 0),

-- Stairs Izquierda - Arriba F3 y Abajo F1 (Morado)
(3, 3, 365.0, 256.0, 'ST-L1-DOWN-F2', 'Escalera F3-F2', 0),
(4, 3, 389.0, 256.0, 'ST-L2-UP-F4', 'Escalera F3-F4', 0),

-- Stairs Derecha - Arriba F3 y Abajo F1 (Morado)
(3, 3, 606.0, 256.0, 'ST-R1-DOWN-F2', 'Escalera F3-F2', 0),
(4, 3, 632.0, 256.0, 'ST-R2-UP-F4', 'Escalera F3-F4', 0),

-- ========================================================

-- Waypoints - Eje Horizontal, Izquierda Edificio (3 puntos)
(0, 3, 437.0, 220.0, 'WP-F3-33', '', 0),
(0, 3, 404.0, 220.0, 'WP-F3-34', '', 0),
(0, 3, 369.0, 220.0, 'WP-F3-35', '', 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (3 puntos)
(0, 3, 558.0, 220.0, 'WP-F3-36', '', 0),
(0, 3, 592.0, 220.0, 'WP-F3-37', '', 0),
(0, 3, 627.0, 220.0, 'WP-F3-38', '', 0);
