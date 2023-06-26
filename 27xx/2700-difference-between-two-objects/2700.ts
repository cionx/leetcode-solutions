/* 2700. Difference Between Two Objects */

type MyObject = { [key: string]: Value };
type Value = Primitive | Nested;
type Primitive = number | boolean | string | null;
type Nested = Value[] | MyObject;

type DiffResult = null | Diff | DiffObject;
type Diff = [Value, Value];
type DiffObject = { [key: string]: Diff | DiffObject };

function isPrimitive(value: Value): value is Primitive {
  const t = typeof (value);
  return t == "number" || t == "boolean" || t == "string" || value == null;
}

function objDiff(object1: MyObject, object2: MyObject): DiffObject {
  const result = objectDiff(object1, object2);
  return (result === null) ? {} : result;
}

function objectDiff(object1: MyObject, object2: MyObject): null | DiffObject {
  const diffs: DiffObject = {};
  let hasDiffs = false;
  for (const key of Object.keys(object1)) {
    if (object2.hasOwnProperty(key)) {
    /* One should use Object.ownProperty(object2, key) instead, but LeeCode is
     * too outdated for that. */
      const entryDiff = valueDiff(object1[key], object2[key]);
      if (entryDiff !== null) {
        hasDiffs = true;
        diffs[key] = entryDiff;
      }
    }
  }
  return hasDiffs ? diffs : null;
}

function valueDiff(value1: Value, value2: Value): DiffResult {
  if (isPrimitive(value1) || isPrimitive(value2)) {
    return (value1 === value2) ? null : [value1, value2];
  }
  const isArray1 = Array.isArray(value1);
  const isArray2 = Array.isArray(value2);
  if (isArray1 && !isArray2 || !isArray1 && isArray2) {
    return [value1, value2];
  }
  if (isArray1 && isArray2) {
    return arrayDiff(value1, value2);
  }
  return objectDiff(value1 as MyObject, value2 as MyObject);
  /* The TypeScript compiler struggels at this point */
}

function arrayDiff(arr1: Value[], arr2: Value[]): null | DiffObject {
  const diffs: DiffObject = {};
  let hasDiff = false;
  for (let i = 0; i < arr1.length && i < arr2.length; ++i) {
    const entryDiff = valueDiff(arr1[i], arr2[i]);
    if (entryDiff !== null) {
      hasDiff = true;
      diffs[i] = entryDiff;
    }
  }
  return hasDiff ? diffs : null;
}
