/* I would like to use Record<string, Value> for MyObject, but this makes
 * TypeScript unable to handle the recursive nature of the types. I’m not sure
 * if this is intended by the TypeScript developers.
 */
type MyObject = { [key: string]: Value };
type Value = Primitive | Nested;
type Primitive = number | string | boolean | null;
type Nested = MyObject | Value[];

/* Type predicate for Primitive. */
function isPrimitive(value: Value): value is Primitive {
  return typeof (value) == "number" || typeof (value) == "string" ||
    typeof (value) == "boolean" || value == null;
}

/* Recursively flattens a nested value (i.e., an object or an array) into a map.
 * This is where the recursion magic happens.
 */
function flattenNested(nested: Nested): Map<string, Primitive> {
  const result: Map<string, Primitive> = new Map();

  for (const [key, value] of Object.entries(nested)) {
    if (isPrimitive(value)) {
      result.set(key, value);
    } else {
      for (const [subkey, subvalue] of flattenNested(value)) {
        result.set(`${key}.${subkey}`, subvalue);
      }
    }
  }

  return result;
}

/* Note: the function signature provided by LeetCode is incorrect. The output
 * type is not an array of primitive values, but a matrix of primitive values.
 */
function jsonToMatrix(arr: Nested[]): Primitive[][] {
  /* Each object is converted into a map whose assignment string -> Primitive
   * will eventually construct the row belonging to this object.
   */
  const maps = arr.map(flattenNested);

  /* We need to determine the string keys corresponding to the matrix columns.
   * We use a set to remove duplicates, and then convert this set to a sorted
   * array. Careful: iterating over a set uses the insertion order, but we need
   * the lexographic order.
   */
  const keys: Set<string> = new Set();
  for (const map of maps) {
    for (const key of map.keys()) {
      keys.add(key);
    }
  }
  const sortedKeys: string[] = Array.from(keys).sort();

  /* Finally, the output matrix. */
  const result: Primitive[][] = [];
  result.push(sortedKeys);
  for (const map of maps) {
    result.push(sortedKeys.map((key) => makeEntry(map, key)));
  }

  return result;
}

/* This function returns either the value associated to the key, or an empty
 * string if there is no associated value. */
function makeEntry<K, V>(map: Map<K, V>, key: K): V | "" {
  if (map.has(key)) {
    return map.get(key) as V;
  } else {
    return "";
  }
}
