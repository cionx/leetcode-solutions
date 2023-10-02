/* 2727. Is Object Empty */

/* Idea.
 * We can check if a key exists by iterating through all keys with a for..in
 * loop. */

type JSONValue = null | boolean | number | string | JSON;
type JSON = JSONValue[] | { [key: string]: JSONValue };

function isEmpty(obj: JSON): boolean {
  for (const _ in obj) {
    return false;
  }
  return true;
}
