INSERT INTO edges (type, status, weight, fromNodeId, toNodeId)
SELECT 0, 1, 10.0,
  (SELECT id FROM nodes WHERE code = n1.code1),
  (SELECT id FROM nodes WHERE code = n1.code2)
FROM (VALUES
  -- Waypoints - Eje Vertical, Entrada a Edificio (4 puntos)
  ('ENTR-F4', 'WP-F4-01'),
  ('WP-F4-01', 'WP-F4-02'),
  ('WP-F4-02', 'WP-F4-03'),
  ('WP-F4-03', 'WP-F4-04'),

  ('WP-F4-04', 'SECU-F4'),
  ('WP-F4-17', 'SECU-F4'),

  ('WP-F4-04', 'EL-EDI-F4'),
  ('WP-F4-21', 'EL-EDI-F4'),

  -- Waypoints - Eje Horizontal, Entrada a Parqueo (8 Puntos)
  ('ENTR-F4', 'WP-F4-05'),
  ('WP-F4-05', 'WP-F4-06'),
  ('WP-F4-06', 'WP-F4-07'),
  ('WP-F4-07', 'WP-F4-08'),
  ('WP-F4-08', 'WP-F4-09'),
  ('WP-F4-09', 'WP-F4-10'),
  ('WP-F4-10', 'WP-F4-11'),
  ('WP-F4-11', 'WP-F4-12'),
  ('WP-F4-12', 'PARK-F4'),

  -- Waypoints - Eje Horizontal, Izquierda Edificio (4 puntos)
  ('WP-F4-04', 'WP-F4-17'),
  ('WP-F4-17', 'WP-F4-18'),
  ('WP-F4-18', 'WP-F4-19'),
  ('WP-F4-19', 'WP-F4-20'),

  ('WP-F4-20', 'R-316'),
  ('WP-F4-19', 'R-317'),
  ('WP-F4-18', 'R-318'),

  ('WP-F4-20', 'ST-L1-UP-F5'),
  ('WP-F4-20', 'ST-L2-DOWN-F3'),

  -- Waypoints - Eje Horizontal, Derecha Edificio (4 puntos)
  ('WP-F4-04', 'WP-F4-21'),
  ('WP-F4-21', 'WP-F4-22'),
  ('WP-F4-22', 'WP-F4-23'),
  ('WP-F4-23', 'WP-F4-24'),

  ('WP-F4-22', 'OFF-F4-D1'),
  ('WP-F4-23', 'OFF-F4-D2'),
  ('WP-F4-24', 'OFF-F4-D3'),

  ('WP-F4-24', 'ST-R1-UP-F5'),
  ('WP-F4-24', 'ST-R2-DOWN-F3')

  -- Waypoints - Eje Vertical, Parqueo a Comedor (4 Puntos)
  ('PARK-F4', 'WP-F4-16'),
  ('WP-F4-16', 'WP-F4-15'),
  ('WP-F4-15', 'WP-F4-14'),
  ('WP-F4-14', 'WP-F4-13'),
  ('WP-F4-13', 'WP-F4-28'),

  -- Waypoints - Eje Horizontal, Puente a Comedor (3 puntos)
  ('WP-F4-13', 'WP-F4-27'),
  ('WP-F4-26', 'WP-F4-25'),
  ('WP-F4-25', 'WP-F4-20'),

  ('WP-F4-27', 'EL-CAF-F4'),
  ('WP-F4-26', 'ST-CAF-DOWN-LIB'),

  -- Waypoints y Bathrooms - Comedor a Biblioteca (Morado)
  ('WP-F4-28', 'CAFE-F4'),
  ('CAFE-F4', 'BATH-F4'),
) AS n1(code1, code2)
WHERE EXISTS (SELECT 1 FROM nodes WHERE code = n1.code1)
  AND EXISTS (SELECT 1 FROM nodes WHERE code = n1.code2);
