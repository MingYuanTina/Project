class Stopwatch {
  constructor() {
    this.start_time = 0;
    this.elapsed_time = 0;
    this.t = 0;
  }

  start() {
    this.start_time = Date.now();  
    this.getElapsedTime(); 
  }

  stop() {
    this.elapsed_time += Date.now() - this.start_time;
    clearTimeout(this.t);
  }

  getElapsedTime() {
    document.getElementById("txt").value = this.elapsed_time;
    this.elapsed_time += Date.now() - this.start_time;
    this.t = setTimeout(sw.getElapsedTime.bind(sw), 1000);
  }
}

var sw = new Stopwatch();