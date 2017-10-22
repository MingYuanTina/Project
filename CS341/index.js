// Design:
	// Parent Class: View 
	// MenuView, ContentPageView
	// Content Page contains two types of ContentDesign
		// SlideContent: Show slides in terms of PDF version
		// CodeContent: Show code in terms of frame (In C++ or JavaScript)

function View(){
	this.d = "This is";
}

function MenuView(){
	this.c = "Menu view";
	
	this.print_view = function(){
		document.getElementById('left').innerHTML = this.c;
	}
	View.call(this);
}

function ContentPageView(){
	this.c = "Content Page View";
	this.print_view = function(){
		document.getElementById('right').innerHTML = this.c;
	}
	View.call(this);
}


MenuView.prototype = Object.create(View);
ContentPageView.prototype = Object.create(View);
MenuView.prototype.constructor = MenuView;
ContentPageView.prototype.constructor = ContentPageView;

var menu = new MenuView();
menu.print_view();
var content = new ContentPageView();
content.print_view();