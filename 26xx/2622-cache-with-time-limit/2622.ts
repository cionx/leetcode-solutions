/* 2622. Cache With Time Limit */

// The return type of setTimeout varies depending on the environment
// in which the code is run (browser, deno, Node.js, etc.). We therefore
// query for this return type.
type Entry = { value: number; timer: ReturnType<typeof setTimeout> };

class TimeLimitedCache {
  cache: Map<number, Entry>;

  constructor() {
    this.cache = new Map();
  }

  set(key: number, value: number, duration: number): boolean {
    const prevEntry = this.cache.get(key);
    const alreadySet = prevEntry != undefined;
    if (alreadySet) {
      clearTimeout(prevEntry.timer);
    }

    const timer = setTimeout(() => this.timeout(key), duration);
    this.cache.set(key, { value, timer });

    return alreadySet;
  }

  get(key: number): number {
    const entry = this.cache.get(key);
    return entry ? entry.value : -1;
  }

  count(): number {
    return this.cache.size;
  }

  private timeout(key: number) {
    this.cache.delete(key);
  }
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
