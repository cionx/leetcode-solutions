/* 2628. JSON Depth Equal */

type Primitive = string | number | boolean | null;
type Json = Primitive | { [property: string]: Json } | Json[];

function isPrimitive(value: Json): value is Primitive {
  return typeof (value) == "number" || typeof (value) == "string" ||
    typeof (value) == "boolean" || value == null;
}

function areDeeplyEqual(o1: Json, o2: Json): boolean {
  if (isPrimitive(o1) || isPrimitive(o2)) return o1 === o2;
  /* In the following, both are either objects or array */

  const keys1 = Object.keys(o1);
  const keys2 = Object.keys(o2);
  if (keys1.length != keys2.length) return false;

  const isArray1 = Array.isArray(o1);
  const isArray2 = Array.isArray(o2);
  if (isArray1 && isArray2) {
    /* We already know they have the same size. */
    for (let i = 0; i < o1.length; i++) {
      if (!areDeeplyEqual(o1[i], o2[i])) return false;
    }
    return true;
  } else if (!isArray1 && !isArray2) {
    for (let i = 0; i < keys1.length; i++) {
      const key = keys1[i];
      if (!areDeeplyEqual(o1[key], o2[key])) return false;
      /* We use here that `undefined` is not an allowed Json value. */
    }
    return true;
  }

  /* One is an array, the other one an object. */
  return false;
}
