class Counter {
	constructor() {
		this.c = 0;
		this.t = 0;
		this.timer_is_on = 0;
	}

	timedCount() {
    document.getElementById("txt").value = this.c;
    this.c = this.c + 1;
    this.t = setTimeout(sw.timedCount.bind(sw), 1000);
	}

	startCount() {
    while (!this.timer_is_on) {
        this.timer_is_on = 1;
        this.timedCount();
    }
	}

	stopCount() {
    clearTimeout(this.t);
    this.timer_is_on = 0;
	}
}

var sw = new Counter();