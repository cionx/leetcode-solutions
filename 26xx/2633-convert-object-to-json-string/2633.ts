type PrimitiveValue = string | number | boolean | null;
type MyObject = PrimitiveValue | MyObject[] | { [key: string]: MyObject };

function jsonStringify(object: MyObject): string {
  switch (typeof object) {
    case "string":
      return `"${object}"`;
    case "number":
      return object.toString();
    case "boolean":
      return object.toString();
    default: {
      if (object === null) {
        return "null";
      }
      if (Array.isArray(object)) {
        return `[${object.map(jsonStringify).join(",")}]`;
      }
      const keys = Object.keys(object);
      return `{${
        keys.map((key) => `"${key}":${jsonStringify(object[key])}`).join(",")
      }}`;
    }
  }
}
