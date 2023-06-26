/* 2694. Event Emitter */

type Callback<T, U> = (...args: T[]) => U;
type Subscription = { unsubscribe: () => undefined };
type Event = string;

class EventEmitter<T, U> {
  private eventRegister: Map<Event, Callback<T, U>[]>;

  constructor() {
    this.eventRegister = new Map();
  }

  subscribe(event: Event, callback: Callback<T, U>): Subscription {
    const cbList = this.eventRegister.get(event);
    if (cbList == undefined) {
      this.eventRegister.set(event, [callback]);
    } else {
      cbList.push(callback);
    }

    return {
      unsubscribe: () => {
        const list = this.eventRegister.get(event);
        if (list !== undefined) {
          this.eventRegister.set(event, list.filter((f) => (f != callback)));
        }
        return undefined;
      },
    };
  }

  emit(event: Event, args: T[] = []): U[] {
    const results = this.eventRegister.get(event)?.map((f) => f(...args));
    return results || []; /* (undefined || []) is [] */
  }
}
