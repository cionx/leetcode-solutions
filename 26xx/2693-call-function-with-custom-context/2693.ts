/* 2693. Call Function with Custom Context */

declare global {
  interface Function {
    callPolyfill(context: Record<string, unknown>, ...args: unknown[]): unknown;
  }
}

Function.prototype.callPolyfill = function (
  context: Record<string, unknown>,
  ...args: unknown[]
): unknown {
  return this.bind(context)(...args);
};
