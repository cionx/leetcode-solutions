type F<T> = (x: T) => T;

// more elegant
function compose<T>(functions: F<T>[]): F<T> {
  return (x: T) => functions.reduceRight((y, f) => f(y), x);
}

// faster
function compose<T>(functions: F<T>[]): F<T> {
  return x => {
    for (let i = functions.length - 1; i >= 0; i--)
      x = functions[i](x);
    return x;
  }
}
