function checkIfInstanceOf(obj: unknown, classFunction: {prototype: unknown}): boolean {
  function isInheritedInstance(proto1: unknown, proto2: unknown): boolean {
    if (proto1 === proto2) {
      return true;
    }
    else if (proto1 !== null) {
      return isInheritedInstance(Object.getPrototypeOf(proto1), proto2);
    }
    return false;
  }

  let objPrototype: unknown;
  let classPrototype: unknown;
  try {
    objPrototype = Object.getPrototypeOf(obj);
    classPrototype = classFunction.prototype;
  } catch (_) {
    return false;
  }
  return isInheritedInstance(objPrototype, classPrototype);
}

/* Testing. */

console.log(checkIfInstanceOf(new Date(), Date) == true);

class Animal {}
class Dog extends Animal {}
console.log(checkIfInstanceOf(new Dog(), Animal) == true);

console.log(checkIfInstanceOf(Date, Date) == false);

console.log(checkIfInstanceOf(5, Number) == true);

class Container {
  value: unknown;
  constructor(value: unknown) {
    this.value = value;
  }
}
class Box {
  value: unknown;
  constructor(value: unknown) {
    this.value = value;
  }
}
console.log(checkIfInstanceOf(new Box(1), Container) == false);
