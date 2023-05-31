type Id = number;
type Station = string;
type Time = number;
type CheckIn = [Station, Time];
type ConnectionData = [total: number, amount: number];

class UndergroundSystem {
  currentCustomers: Map<Id, CheckIn>;
  connectionData: Map<Station, Map<Station, ConnectionData>>;
  /* In JS/TS, you cannot index by pairs of strings. Kinda garbage. */

  constructor() {
    this.currentCustomers = new Map();
    this.connectionData = new Map();
  }

  checkIn(id: Id, startStation: Station, startTime: Time): void {
    this.currentCustomers.set(id, [startStation, startTime]);
  }

  checkOut(id: Id, endStation: Station, endTime: Time): void {
    const checkin = this.currentCustomers.get(id);
    if (checkin === undefined) {
      throw new Error(`Customer ${id} did not check in`);
    }
    const [startStation, startTime] = checkin;
    const timeDiff = endTime - startTime;

    const startData = this.connectionData.get(startStation);
    if (startData === undefined) {
      const newDrivingData = new Map();
      newDrivingData.set(endStation, [timeDiff, 1]);
      this.connectionData.set(startStation, newDrivingData);
    }
    else {
      const connectionData = startData.get(endStation);
      if (connectionData === undefined) {
        startData.set(endStation, [timeDiff, 1]);
      }
      else {
        const [total, amount] = connectionData;
        startData.set(endStation, [total + timeDiff, amount + 1]);
      }
    }

    this.currentCustomers.delete(id);
  }

  getAverageTime(start: Station, end: Station): number {
    const connectionData = this.connectionData.get(start)?.get(end);
    if (connectionData === undefined) {
      throw new Error(`No data about connection from ${start} to ${end}`);
    }
    const [total, amount] = connectionData;
    return total / amount;
  }
}
