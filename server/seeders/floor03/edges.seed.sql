INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Eje Horizontal, Centro --- */
  SELECT 'BATH-F3', 'CHILL-F3' UNION ALL
  SELECT 'BATH-F3', 'EL-EDI-F3' UNION ALL

  /* --- Eje Horizontal, Izquierda Edificio --- */
  SELECT 'BATH-F3', 'WP-F3-33' UNION ALL
  SELECT 'WP-F3-33', 'WP-F3-34' UNION ALL
  SELECT 'WP-F3-34', 'WP-F3-35' UNION ALL

  SELECT 'WP-F3-33', 'R-312-F3' UNION ALL
  SELECT 'WP-F3-34', 'R-311-F3' UNION ALL
  SELECT 'WP-F3-35', 'R-310-F3' UNION ALL

  SELECT 'WP-F3-35', 'ST-L2-UP-F4' UNION ALL
  SELECT 'WP-F3-35', 'ST-L1-DOWN-F2' UNION ALL

  /* --- Eje Horizontal, Derecha Edificio --- */
  SELECT 'BATH-F3', 'WP-F3-36' UNION ALL
  SELECT 'WP-F3-36', 'WP-F3-37' UNION ALL
  SELECT 'WP-F3-37', 'WP-F3-38' UNION ALL

  SELECT 'WP-F3-36', 'R-313-F3' UNION ALL
  SELECT 'WP-F3-37', 'R-314-F3' UNION ALL
  SELECT 'WP-F3-38', 'R-315-F3' UNION ALL

  SELECT 'WP-F3-38', 'ST-R2-UP-F4' UNION ALL
  SELECT 'WP-F3-38', 'ST-R1-DOWN-F2'
)
SELECT 0, 3, 1, 10.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;
