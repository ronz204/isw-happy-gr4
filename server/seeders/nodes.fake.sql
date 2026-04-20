-- UTN San Carlos Campus Nodes
-- Floor 0 = Ground floor, Floor 1 = First floor, Floor 2 = Second floor

-- Ground Floor (Floor 0) - Main Campus
INSERT INTO nodes (id, type, floor, px, py, code, label, isLandmark, landmarkLvl) VALUES
-- Entrances and Parking (landmarks)
(1, 6, 0, 10.0, 10.0, 'ENT-MAIN', 'Entrada Principal', 1, 1),
(2, 9, 0, 5.0, 5.0, 'PARK-01', 'Parqueo Principal', 1, 3),

-- Main Building - Ground Floor
(3, 5, 0, 20.0, 10.0, 'JCT-01', 'Cruce Edificio Principal', 0, 0),
(4, 8, 0, 25.0, 10.0, 'CAF-01', 'Cafetería Central', 1, 2),
(5, 7, 0, 30.0, 10.0, 'LIB-01', 'Biblioteca', 1, 1),
(6, 4, 0, 35.0, 10.0, 'BATH-01', 'Baños Edificio Principal', 0, 0),

-- Stairs and Elevators to upper floors
(7, 2, 0, 40.0, 10.0, 'STAIR-01', 'Escaleras Edificio Principal', 0, 0),
(8, 3, 0, 42.0, 10.0, 'ELEV-01', 'Elevador Edificio Principal', 0, 0),

-- Admin Building - Ground Floor
(9, 5, 0, 50.0, 10.0, 'JCT-02', 'Cruce Administración', 0, 0),
(10, 10, 0, 55.0, 10.0, 'OFF-01', 'Oficinas Administrativas', 1, 2),
(11, 10, 0, 60.0, 10.0, 'OFF-02', 'Registro y Matrícula', 1, 3),

-- Labs Building - Ground Floor
(12, 5, 0, 70.0, 10.0, 'JCT-03', 'Cruce Laboratorios', 0, 0),
(13, 12, 0, 75.0, 10.0, 'LAB-01', 'Laboratorio Computación', 0, 0),
(14, 12, 0, 80.0, 10.0, 'LAB-02', 'Laboratorio Electrónica', 0, 0),
(15, 2, 0, 85.0, 10.0, 'STAIR-02', 'Escaleras Labs', 0, 0),

-- First Floor (Floor 1) - Main Building
(16, 5, 1, 40.0, 20.0, 'JCT-04', 'Cruce Primer Piso', 0, 0),
(17, 11, 1, 35.0, 20.0, 'CLASS-01', 'Aula 101', 0, 0),
(18, 11, 1, 30.0, 20.0, 'CLASS-02', 'Aula 102', 0, 0),
(19, 11, 1, 45.0, 20.0, 'CLASS-03', 'Aula 103', 0, 0),
(20, 4, 1, 50.0, 20.0, 'BATH-02', 'Baños Primer Piso', 0, 0),

-- First Floor - Labs Building
(21, 5, 1, 85.0, 20.0, 'JCT-05', 'Cruce Labs Primer Piso', 0, 0),
(22, 12, 1, 80.0, 20.0, 'LAB-03', 'Laboratorio Redes', 0, 0),
(23, 12, 1, 75.0, 20.0, 'LAB-04', 'Laboratorio Física', 0, 0),

-- Second Floor (Floor 2) - Auditorium
(24, 5, 2, 40.0, 30.0, 'JCT-06', 'Cruce Segundo Piso', 0, 0),
(25, 13, 2, 45.0, 30.0, 'AUD-01', 'Auditorio Principal', 1, 2),
(26, 11, 2, 35.0, 30.0, 'CLASS-04', 'Aula 201', 0, 0),
(27, 4, 2, 50.0, 30.0, 'BATH-03', 'Baños Segundo Piso', 0, 0);
