-- Aristas siguiendo las líneas blancas de la imagen
-- type=0 (Walking), status=1 (Open), weight=10.0
INSERT INTO edges (type, status, weight, fromNodeId, toNodeId)
SELECT 0, 1, 10.0,
  (SELECT id FROM nodes WHERE code = n1.code1),
  (SELECT id FROM nodes WHERE code = n1.code2)
FROM (VALUES
  -- Zona de Baños del Comedor
  ('WP-F4-01', 'WP-F4-02'),
  ('WC-M-F4', 'WP-F4-01'),
  ('WC-F-F4', 'WP-F4-01'),

  -- Zona de Pasillo del Comedor
  ('WP-F4-01', 'WP-F4-02'),
  ('WP-F4-02', 'WP-F4-03'),

  -- Zona Central del Comedor
  ('WP-F4-01', 'DIN-F4'),
  ('WP-F4-02', 'DIN-F4'),
  ('WP-F4-03', 'DIN-F4'),

  -- =========================================

  -- Waypoints - Eje Vertical de Comedor a Parqueo
  ('WP-F4-03', 'WP-F4-04'),
  ('WP-F4-04', 'WP-F4-05'),
  ('WP-F4-05', 'WP-F4-06'),
  ('WP-F4-06', 'WP-F4-07'),

  -- Waypoints - Parqueo (6 puntos)
  ('WP-F4-07', 'WP-F4-08'),
  ('WP-F4-08', 'WP-F4-09'),
  ('WP-F4-09', 'WP-F4-10'),
  ('WP-F4-10', 'WP-F4-11'),
  ('WP-F4-11', 'WP-F4-12'),
  ('WP-F4-12', 'WP-F4-13'),

  -- =========================================

  -- Waypoints - Conectividad Vertical Comedor - Biblioteca
  ('WP-F4-04', 'WP-F4-05'),
  ('WP-F4-05', 'EL-C1-CAF-F4'),
  ('WP-F4-05', 'WP-F4-06'),
  ('WP-F4-06', 'ST-DOWN-LIBRARY'),
) AS n1(code1, code2)
WHERE EXISTS (SELECT 1 FROM nodes WHERE code = n1.code1)
  AND EXISTS (SELECT 1 FROM nodes WHERE code = n1.code2);
