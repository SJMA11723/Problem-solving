# Bitácora ICPC — Jorge Raúl Tzab López

## Problemas
| Fecha | Problema/Contest | Rating | Resultado (Solo (AC) /Pistas N (AC)/WA/TLE/No) | Técnica | Error | Qué repasar |
|---|---|---|---|---|---|---|
| 2026-09-27 | Gym 106540F Forever in love | n≤20 | Pistas | Bitmask DP (capas popcount), pref-min + BS | RE→MLE→TLE, cte. alta | Acotar memoria bitmask antes de codificar; capas popcount |
| 2026-10-04 | Gym 106178C Clean Streets | LATAM 25-26 | Pistas | Fijar r, greedy H, sweep + BIT | RE (desempate inestable `sort`) | Comparador estrictamente antisimétrico en floats/claves compuestas |
| 2026-10-10 | Gym 105505G Grand Glory Race | LATAM 24-25 | Pistas | Rerooting (best/2nd_best + cnt) | WA (desempate id leaf) | Manejo de desempate por id de hoja en rerooting |
| 2026-10-11 | Gym 105505H Heraclosures | LATAM 24-25 | Pistas | Sqrt decomp, pendientes (k=√M) | WA (orden cronológico) | Aplicar updates pendientes en orden con umbral √M |
| 2026-10-17 | Gym 105505I Inversion Insight | LATAM 24-25 | Pistas | DP CDF(i,x) inversiones, capado | Bloqueo conceptual | Recurrencia inversiones por posición; capar en vez de `__int128` |
| 2026-10-18 | Gym 104736C Candy Rush | LATAM 23-24 | Pistas | Hash polinomial freq. norm. (`C^color`) | WA (scope), MLE (`map<vi,int>`) | Pertenencia a subespacio (vec **1**) vía hashing |
| 2026-10-29 | TAP 2026M Malbec | TAP 26 | Pistas | Sqrt decomp, lazy/bloque, cascada izq. | WA (L,R mismo bloque sin flush) | Flush explícito de bloques frontera siempre (incl. mismo bloque) |
| 2026-10-31 | Gym 106189K Factorials | Russia 25 | No | Legendre por primo, cota a-b | - | Retomar con editorial; pendientes C e I del mismo contest |
| 2026-11-01 | CSES 2080 Fixed-Length Paths I | CSES | Pistas | Centroid decomp, dist[] rama, cnt[] global | TLE (`unordered_map`), `>=` vs `>` | Sin `unordered_map` en hot path; centroide estricto `sub[v]>n/2` |
| 2026-11-01 | CSES 2081 Fixed-Length Paths II | CSES | Pistas | Centroid decomp, prefijos estáticos | TLE (BIT log extra), rango vacío | Prefijos estáticos por centroide vs BIT; filtrar rangos vacíos |
| 2026-11-02 | CSES 1139 Distinct Colors | CSES | Pistas | Sack / DSU on tree | TLE (typo `sub[u]` vs `sub[v]`) | Verificar condiciones de cota (heavy child) ante TLE silencioso |
| 2026-11-02 | CSES 2134 Path Queries II | CSES | No | HLD + SegTree max (pendiente) | - | `max` no es invertible para Euler tour; resolver con HLD |
| 2026-11-13 | CF 762E Radio stations | Div1/2 E | Solo | Treap multiset por freq, contar [a,b] | - | Comparar treap vs BIT por frecuencia (editorial) |
| 2026-11-13 | SPOJ ADAAPHID | - | Solo | Treap multiset | Enunciado confuso | - |
| 2026-11-14 | SPOJ IITWPC4D Arrangement Validity | - | Pistas | Treap k-ésimo, reconstrucción n→1 | RE (`A[i]≥i`), bug aritm. `kth` | Preferir `kth` con k relativo decreciente |
| 2026-11-15 | CF 847D Dog Show | Div2 D/E | Solo | Treap clave `t_i-i`, contar ≤ `T-i` | - | Patrón transformar antes de insertar (`v_i=t_i-i`) |
| 2026-11-15 | CF 863D Array Queries | Div2 D | Solo | Implicit treap: reverse + right_shift | - | Ref. limpia de implicit treap con lazy reverse |
| 2026-11-15 | SPOJ MEANARR Mean of array | - | Solo | D&C + treap `lt()` sumas prefijo | - | Reciclar pool post-order (`nxt_node=1`) |
| 2026-11-20 | CF 167D Wizards and Roads | 3000 | Solo | Cartesiano (x/y) + treap, DP matching [L,R] | - | Repasar prueba de equivalencia con árbol cartesiano |
| 2026-11-20 | CF 295E Yaroslav and Points | Div1 E | Solo | Treap aumentado (`cnt,sum,sum_dist`) | Faltó término cruzado izq-der | En agregados de pares, incluir término cruzado en `recalc()` |
| 2026-11-21 | CF 1777F Comfortably Numb | Div1 F | Solo | Cartesiano max + trie XOR + small-to-large | Dangling ref `&`; faltó par intervalos | Revisar caso borde del par de intervalos faltante |
| 2026-11-22 | CF 2268C KiaKio Energy Intervals | Medio-alto | Solo | Bit a bit (MSB→LSB) + factibilidad cartesiano | Max XOR antes de máscara ≠ max enmascarado | Probar bits MSB→LSB verificando submáscara en max e intervalo |
| 2026-11-22 | SPOJ TEMPLEQ Temple Queues | - | Pistas | Treap con punteros a padre + lazy | Confundir arreglo externo vs treap | Treap como única fuente de verdad; padre para clave externa |
| 2026-11-23 | SPOJ HORRIBLE | - | Pistas | Implicit treap, lazy aditivo | `sum` sin actualizar en lazy; falta `push` | Actualizar agregado al cambiar lazy; `push` hijos antes de `recalc` |
| 2026-11-24 | CF 1021D Hitchhiking Baltic States | Div1/2 D | Pistas | LIS O(n log n) intervalos, implicit treap | Bloqueo por dep. de "punto anterior" | Conectar DP de secuencias crecientes con tails array de LIS |
| 2026-11-27 | CF Sneetches and Speeches 3 (C) | - | Pistas | Treap implícito, lazy combinado (rev + xor + assign vía sort) | WA no determinista: (1) `cnt1` sin actualizar en `apply_lz` al aplicar `lzupt`; (2) `xor1` no se limpiaba al cascadear un `lzupt` nuevo en `push`, violando dominancia assign>xor | Dominancia entre lazies no conmutativos; orden de aplicación en `apply_lz` (assign antes que xor) y limpieza explícita del lazy relativo al propagar un assign en `push()` |

## Repertorio de técnicas
| Técnica | Cuándo sospecharla | Problemas |
|---|---|---|
| Treap multiset (orden-estadístico) | Inserción dinámica + "cuántos ≤ x" o k-ésimo en O(log n) | CF 762E, 847D; SPOJ MEANARR, IITWPC4D |
| Implicit treap + lazy | Insert/erase por posición, reverse, rotación o range-add sin SegTree | CF 863D, 1021D; SPOJ HORRIBLE |
| Cartesiano + split/merge | Aislar query [L,R] como subproblema independiente con DP/agregado | CF 167D, 295E |
| D&C sobre max de rango (pila monótona) | El max/min del subarreglo fija una propiedad y se agregan ambos lados | CF 847D, 1777F, 2268C |
| Treap aumentado (combinatoria) | Agregado sobre todos los pares de un subárbol (cuidar término cruzado) | CF 295E |
| Treap con punteros a padre | Ubicar/modificar nodo por índice externo bajo lazy pendiente | SPOJ TEMPLEQ |
| Small-to-large / Sack (DSU on tree) | Combinar estructuras de subárboles (distintos, tries) sin recomputar; O(log n) movs/elem | CSES 1139; CF 1777F, 2268C |
| Respuesta bit a bit (MSB→LSB) | Maximizar combinación AND/XOR donde optimizar por partes falla; validar factibilidad | CF 2268C |
| Reconstrucción vía k-ésimo (n→1) | Conteo relativo de mayores/menores ya colocados para recuperar permutación | SPOJ IITWPC4D |
| LIS en intervalos (tails + treap/BS) | LIS donde cada elemento elige libremente dentro de un intervalo | CF 1021D |
| Sqrt decomp + lazy/pendientes | Range update/query incómodo para SegTree (cascadas entre bloques o buffer √M) | TAP 2026M; Gym 105505H |
| Centroid decomposition | Conteo de pares de nodos en árbol con condición sobre distancia | CSES 2080, 2081 |
| Hashing sobre vectores (subespacio) | Validar que vector de frecuencias iguala X o pertenece a subespacio (ej. vec **1**) | Gym 104736C |
| Lazy dominante sobre lazy relativo (assign anula xor/add) | Estructura con reverse + xor/add + assign combinados; WA que depende de la forma del árbol/estructura al mezclar operaciones de distinto tipo sobre el mismo rango | CF Sneetches and Speeches 3 |

## Errores crónicos
- **Lazy/recalc:** actualizar el campo agregado en el mismo instante que cambia `lz`, y hacer `push` a hijos antes de `recalc()` (HORRIBLE).
- **Pool allocator:** revisar margen `pool[MAXN+1]` según inicio en 0 o 1 (IITWPC4D).
- **Optimización compuesta:** $\max f(g(x)) \neq f(\max g(x))$; evaluar bit a bit + factibilidad (CF 2268C).
- **Typos de complejidad:** un carácter mal (`sub[u]` vs `sub[v]`) da TLE silencioso; auditar condiciones de heavy child/centroide (CSES 1139).