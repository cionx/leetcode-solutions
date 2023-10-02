/* 2722. Join Two Arrays by ID. */

/* Idea.
 * To merge two entries
 *    entry1 = {"id": 2, "x": 3, "y": 6}
 *    entry2 = {"id": 2, "x": 10, "y": 20}
 * we start with an empty object {}, then copy every key-value pair of entry1
 * into it, and then copy every key-value pair of entry2 into it. This will
 * automatically overwrite existing key-value pairs coming from entry1.
 *
 * For better access we convert an array
 *    [entry1, entry2, ...]
 * into an an “accessible object”
 *    {id1: entry1, id2: entry2, ...}.
 * This gives us two accessible objects acc1 and acc2 that we need to merge.
 * For this merging we start with result = acc1. For every key-value pair
 * (id, entry) of acc2 we then have two cases to consider:
 * - If `id` is also a key for acc1, then we need to merge the two entries
 *   acc1[id] and acc2[id], as described above. We then set result[id] to this
 *   merged entry.
 * - Otherwise we simply set result[id] = acc2[id].
 * The end result is another accessible object. We convert this object back
 * into an array, and then sort the array entries by their ids. */

type JSONValue = null | boolean | number | string | JSONObject;
type JSONObject = JSONValue[] | { [key: string]: JSONValue };
type Entry = { "id": number; [key: string]: JSONValue };
/* We abuse here the fact that `number` is a subtype of JSONValue. */

function accessibleEntries(entries: Entry[]): { [id: number]: Entry } {
  const result: { [id: number]: Entry } = {};
  for (const entry of entries) {
    result[entry["id"]] = entry;
  }
  return result;
}

function mergeEntries(entry1: Entry, entry2: Entry): Entry {
  const result: Entry = { "id": 0 }; /* Dummy id value for the type checker. */
  for (const key in entry1) {
    result[key] = entry1[key];
  }
  for (const key in entry2) {
    result[key] = entry2[key];
  }
  return result;
}

function join(arr1: Entry[], arr2: Entry[]): Entry[] {
  const acc1 = accessibleEntries(arr1);
  const acc2 = accessibleEntries(arr2);

  const accResult = acc1;
  for (const id in acc2) {
    if (accResult[id] !== undefined) {
      accResult[id] = mergeEntries(accResult[id], acc2[id]);
    } else {
      accResult[id] = acc2[id];
    }
  }

  const result = Object.values(accResult);
  result.sort((entry1, entry2) => entry1["id"] - entry2["id"]);

  return result;
}
