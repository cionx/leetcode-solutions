type F<T> = (x: T) => T;

function compose<T>(functions: F<T>[]): F<T> {
  return (x: T) => functions.reduceRight((y, f) => f(y), x);
}
