/* 2705. Compact Object */

type primitiveJSONValue = null | boolean | number | string;
type JSONValue = primitiveJSONValue | JSONObject;
type JSONObject = JSONArray | JSONRecord;
type JSONArray = JSONValue[];
type JSONRecord = { [key: string]: JSONValue };

function isTruthy(value: primitiveJSONValue): boolean {
  return Boolean(value);
}

function isPrimitive(value: JSONValue): value is primitiveJSONValue {
  return value === null || typeof value === "boolean" ||
    typeof value === "number" ||
    typeof value === "string";
}

function isArray(obj: JSONObject): obj is JSONArray {
  return Array.isArray(obj);
}

function compactValue(value: JSONValue): JSONValue | undefined {
  if (isPrimitive(value)) {
    return isTruthy(value) ? value : undefined;
  }
  return compactObject(value);
}

function compactObject(obj: JSONObject): JSONObject {
  if (isArray(obj)) {
    return compactArray(obj);
  }
  return compactRecord(obj);
}

function compactArray(arr: JSONArray): JSONArray {
  const result: JSONArray = [];
  for (let i = 0; i < arr.length; ++i) {
    const cValue = compactValue(arr[i]);
    if (cValue !== undefined) {
      result.push(cValue);
    }
  }
  return result;
}

function compactRecord(rec: JSONRecord): JSONRecord {
  const result: JSONRecord = {};
  for (const key in rec) {
    const cValue = compactValue(rec[key]);
    if (cValue !== undefined) {
      result[key] = cValue;
    }
  }
  return result;
}
