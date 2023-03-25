$(document).ready(function(){
	$(".img").hover(function(){
		$(this).animate({
			width: "+=100px"
		},100);
	}, function(){
		$(this).animate({
			width: "-=100px"
		},100);
	});
});
