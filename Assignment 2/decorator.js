var Label = function(labelText,x,y){
	var that = {};
	var labelText_=labelText || "";
	var x_=x || 200;
	var y_=y || 200;
	/*These functions are useless now
	var hasBorder_ = false;
	var hasThickRectBorder_= false;
	var hasDots_ = false;*/
	var width_ = labelText_.length * 10;
	var height_ = 40;
	//getter functions that gets the current size of the x,y,width,height values, so that the borders can be added on top
	that.getX = function() { return x_; };
	that.getY = function() { return y_; };
	that.getWidth = function() { return width_; };
	that.getHeight = function() { return height_; };
	//getter functions that subtract 20 for the remove function
	that.subX = function() { return x_ -= 20; };
	that.subY = function() { return y_ -= 20; };
	that.subW = function() { return width_ -= 20; };
	that.subH = function() { return height_ -= 20; };

	that.draw = function() {
		strokeWeight(1);
		stroke(0,0,0);
		fill(0,0,0);
		textAlign(CENTER);
		text(labelText_, x_, y_);
	}
	return that;
};

var addThickBorder = function(l) {
	var that = {};
	that.getX = function () { return l.getX(); }
	that.getY = function() { return l.getY(); };
	that.getWidth = function() { return l.getWidth() + 20; };
	that.getHeight = function() { return l.getHeight() + 20; };
	
	that.draw = () => {
		rectMode(CENTER);
		strokeWeight(3);
		stroke(0,0,0);
		noFill();
		rect(that.getX(), that.getY(), that.getWidth(), that.getHeight());
		l.draw();
	}
	return that;
}

var addThinBorder = function(l) {
	var that = {};
	that.getX = function () { return l.getX(); }
	that.getY = function() { return l.getY(); };
	that.getWidth = function() { return l.getWidth() + 20; };
	that.getHeight = function() { return l.getHeight() + 20; };
	
	that.draw = () => {
		rectMode(CENTER);
		strokeWeight(1);
		stroke(0,0,0);
		noFill();
		rect(that.getX(), that.getY(), that.getWidth(), that.getHeight());
		l.draw();
	}
	return that;
}

var addDotBorder = function(l) {
	var that = {};
	that.getX = function () { return l.getX(); }
	that.getY = function() { return l.getY(); };
	that.getWidth = function() { return l.getWidth() + 20; }; //only 20 works.. 15 causes it to be uneven
	that.getHeight = function() { return l.getHeight() + 20; };
	
	that.draw = () => {
		ellipseMode(CENTER);
		strokeWeight(1);
		fill(255, 0, 0);
		stroke(255, 0, 0);
		//above label
		for (var i = 0; i < that.getWidth() / 10 + 1; i++) {
			ellipse((that.getX() - that.getWidth() / 2 + i * 10), (that.getY() - that.getHeight() / 2), 5, 5);
			
		}
		//below label
		for (var i = 0; i < that.getWidth() / 10 + 1; i++) {
			ellipse((that.getX() - that.getWidth() / 2 + i * 10), (that.getY() + that.getHeight() / 2), 5, 5);
		}
		//left of label
		for (var i = 0; i < that.getHeight() / 10 - 1; i++) {
			ellipse((that.getX() - that.getWidth() / 2), (that.getY() - that.getHeight() / 2 + ((i + 1) * 10)), 5, 5);
		}
		//right of label
		for (var i = 0; i < that.getHeight() / 10 - 1; i++) {
			ellipse((that.getX() + that.getWidth() / 2), (that.getY() - that.getHeight() / 2 + ((i + 1) * 10)), 5, 5);
		}
		l.draw();
	}
	return that;
}

var removeLast = function(l) {
	var that = {};

	that.getX = function () { return l.getX(); }
	that.getY = function() { return l.getY(); };
	that.getWidth = function() { return l.getWidth() };
	that.getHeight = function() { return l.getHeight() };

	that.draw = () => {
		rectMode(CENTER);
		strokeWeight(5);

		stroke(0,255,255);
		noFill();
		rect(that.getX(), that.getY(), that.getWidth(), that.getHeight());
		l.draw();
		//that.subX();
		//that.subY();
		//that.subW();
		//that.subH();
	}
	return that;
}

var l;
var thickBorderButton;
var borderButton;
var dotButton;
var removeButton;
function addBorder(){
	l = addThinBorder(l);
}
function addThick(){
	l = addThickBorder(l);
}
function addDots(){
	l = addDotBorder(l);
}
function rmv() {
	l = removeLast(l);
}

function setup(){
    thickBorderButton=createButton("Add Thick Border");
    thickBorderButton.mousePressed(addThick);
    borderButton=createButton("Add Border");
    borderButton.mousePressed(addBorder);
    dotButton=createButton("Add Dots Border");
	dotButton.mousePressed(addDots);
	//remove button
	removeButton=createButton("Remove Last");
	removeButton.mousePressed(rmv);

	createCanvas(500,500);
	l = Label("the Label", 100,100);

}

function checkBorder(){
	l.toggleDots();
}

function draw(){
	background(255,255,255);
	l.draw();
}
	