INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Eje Horizontal, Centro --- */
  SELECT 'BATH-F2', 'SECU-F2' UNION ALL
  SELECT 'BATH-F2', 'EL-EDI-F2' UNION ALL

  /* --- Eje Horizontal, Izquierda Edificio --- */
  SELECT 'BATH-F2', 'WP-F2-27' UNION ALL
  SELECT 'WP-F2-27', 'WP-F2-28' UNION ALL
  SELECT 'WP-F2-28', 'WP-F2-29' UNION ALL

  SELECT 'WP-F2-27', 'R-307-F2' UNION ALL
  SELECT 'WP-F2-28', 'R-308-F2' UNION ALL
  SELECT 'WP-F2-29', 'R-309-F2' UNION ALL

  SELECT 'WP-F2-29', 'ST-L1-UP-F3' UNION ALL
  SELECT 'WP-F2-29', 'ST-L2-DOWN-F1' UNION ALL

  /* --- Eje Horizontal, Derecha Edificio --- */
  SELECT 'BATH-F2', 'WP-F2-30' UNION ALL
  SELECT 'WP-F2-30', 'WP-F2-31' UNION ALL
  SELECT 'WP-F2-31', 'WP-F2-32' UNION ALL

  SELECT 'WP-F2-31', 'AUDITORIO-F2' UNION ALL

  SELECT 'WP-F2-32', 'ST-R1-UP-F3' UNION ALL
  SELECT 'WP-F2-32', 'ST-R2-DOWN-F1'
)
SELECT 0, 2, 1, 10.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;
