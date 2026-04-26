INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Eje Vertical, Entrada a Edificio --- */
  SELECT 'ENTR-F4', 'WP-F4-01' UNION ALL
  SELECT 'WP-F4-01', 'WP-F4-02' UNION ALL
  SELECT 'WP-F4-02', 'WP-F4-03' UNION ALL
  SELECT 'WP-F4-03', 'SECU-F4'  UNION ALL
  SELECT 'WP-F4-03', 'EL-EDI-F4' UNION ALL
  
  /* --- Eje Horizontal, Entrada a Parqueo --- */
  SELECT 'ENTR-F4', 'WP-F4-04' UNION ALL
  SELECT 'WP-F4-04', 'WP-F4-05' UNION ALL
  SELECT 'WP-F4-05', 'WP-F4-06' UNION ALL
  SELECT 'WP-F4-06', 'WP-F4-07' UNION ALL
  SELECT 'WP-F4-07', 'WP-F4-08' UNION ALL
  SELECT 'WP-F4-08', 'PARK-F4'  UNION ALL

  /* --- Eje Vertical, Parqueo a Comedor --- */
  SELECT 'PARK-F4', 'WP-F4-09' UNION ALL
  SELECT 'WP-F4-09', 'WP-F4-10' UNION ALL
  SELECT 'WP-F4-10', 'WP-F4-11' UNION ALL
  SELECT 'WP-F4-11', 'WP-F4-12' UNION ALL

  /* --- Eje Horizontal, Comedor --- */
  SELECT 'WP-F4-12', 'CAFE-F4' UNION ALL
  SELECT 'CAFE-F4', 'BATH-F4' UNION ALL

  /* --- Eje Horizontal, Izquierda Edificio --- */
  SELECT 'WP-F4-03', 'WP-F4-13' UNION ALL
  SELECT 'WP-F4-13', 'WP-F4-14' UNION ALL
  SELECT 'WP-F4-14', 'WP-F4-15' UNION ALL

  SELECT 'WP-F4-15', 'R-316-F4' UNION ALL
  SELECT 'WP-F4-14', 'R-317-F4' UNION ALL
  SELECT 'WP-F4-13', 'R-318-F4' UNION ALL

  SELECT 'WP-F4-15', 'ST-L1-UP-F5' UNION ALL
  SELECT 'WP-F4-15', 'ST-L2-DOWN-F3' UNION ALL

  /* --- Eje Horizontal, Derecha Edificio --- */
  SELECT 'WP-F4-03', 'WP-F4-16' UNION ALL
  SELECT 'WP-F4-16', 'WP-F4-17' UNION ALL
  SELECT 'WP-F4-17', 'WP-F4-18' UNION ALL

  SELECT 'WP-F4-16', 'OFF-F4-D1' UNION ALL
  SELECT 'WP-F4-17', 'OFF-F4-D2' UNION ALL
  SELECT 'WP-F4-18', 'OFF-F4-D3' UNION ALL

  SELECT 'WP-F4-18', 'ST-R1-UP-F5' UNION ALL
  SELECT 'WP-F4-18', 'ST-R2-DOWN-F3' UNION ALL

  /* --- Eje Horizontal, Puente a Comedor --- */
  SELECT 'WP-F4-15', 'WP-F4-19' UNION ALL
  SELECT 'WP-F4-19', 'WP-F4-20' UNION ALL
  SELECT 'WP-F4-20', 'WP-F4-11' UNION ALL

  SELECT 'WP-F4-20', 'EL-CAF-F4' UNION ALL
  SELECT 'WP-F4-20', 'ST-CAF-F4'
)
SELECT 0, 4, 1, 10.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;
