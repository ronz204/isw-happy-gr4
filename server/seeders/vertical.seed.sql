INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Vertical, Stairs F5-F4 --- */
  SELECT 'ST-L1-DOWN-F4', 'ST-L1-UP-F5' UNION ALL
  SELECT 'ST-R1-DOWN-F4', 'ST-R1-UP-F5' UNION ALL

  /* --- Vertical, Stairs F4-F3 --- */
  SELECT 'ST-L2-DOWN-F3', 'ST-L2-UP-F4' UNION ALL
  SELECT 'ST-R2-DOWN-F3', 'ST-R2-UP-F4' UNION ALL

  /* --- Vertical, Stairs F3-F2 --- */
  SELECT 'ST-L1-DOWN-F2', 'ST-L1-UP-F3' UNION ALL
  SELECT 'ST-R1-DOWN-F2', 'ST-R1-UP-F3'
)
SELECT 1, 0, 1, 5.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;


INSERT INTO edges (type, floor, status, weight, fromNodeId, toNodeId)
WITH raw_connections(c1, c2) AS (
  /* --- Vertical, Elevator F5-F4 --- */
  SELECT 'EL-EDI-F5', 'EL-EDI-F4' UNION ALL

  /* --- Vertical, Elevator F4-F3 --- */
  SELECT 'EL-EDI-F4', 'EL-EDI-F3' UNION ALL

  /* --- Vertical, Elevator F3-F2 --- */
  SELECT 'EL-EDI-F3', 'EL-EDI-F2'
)
SELECT 2, 0, 1, 2.0, n1.id, n2.id
FROM raw_connections
JOIN nodes n1 ON n1.code = raw_connections.c1
JOIN nodes n2 ON n2.code = raw_connections.c2;
