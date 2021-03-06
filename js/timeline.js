// Timeline Controls
(function ($) {
	Drupal.behaviors.views_timeline = {
		attach: function(context, settings) {
			var results = $('li.eventSlide');
				index = 0;
				visible = 4;
				endIndex = (results.length) - 1;
				scrollPos = 0;
			
			$('.timelineControls a.btnPrevious').click(function () { 
				var leftPos = $('.timelineWrapper').scrollLeft();
				$('.timelineWrapper').animate({scrollLeft: leftPos - 200}, 800);
				return false;
			});
			
			$('.timelineControls a.btnNext').click(function () { 
				var leftPos = $('.timelineWrapper').scrollLeft();
				$( '.timelineWrapper' ).animate({scrollLeft: leftPos + 200}, 800);
				return false;
			});
			
			// Timeline Slide Width
			$('.eventSlide').click(function() {
				$('.eventSlide.active').not(this).removeClass('active');
				$(this).toggleClass('active');
				$(this).toggleClass('');
			});
			
			// Almost works correctly... Sigh.
			$('.timelineSelector a').click(function () {
				date = $(this).html();
				events = $('.eventSlide');
				event = $('li.eventSlide').filter('.year' + date);
				
				currentIndex = events.index(event);
				scrollTo = currentIndex * 200;
				$( '.timelineWrapper' ).animate({scrollLeft: scrollTo}, 800);
				
				//reset and highlight the clicked link
				$('.timelineSelector a').removeClass('selected');
				$(this).addClass('selected');
				
				//grab the current item
				current = $(this);
				
				//scroll it to the destination
				//$('#timelineWrapper').scrollTo($(this).attr('href'), 800);
				//cancel the link default behavior
				return false;
			});
			
		}
			
	}
	
	
}(jQuery));
//	$('.timelineControls a.btnPrevious').click(function () { 
//		var leftPos = $('.timelineWrapper').scrollLeft();
//		 $('.timelineWrapper').animate({scrollLeft: leftPos - 200}, 800);
//	});
//	$('.timelineControls a.btnNext').click(function () { 
//		var leftPos = $('.timelineWrapper').scrollLeft();
//		$( '.timelineWrapper' ).animate({scrollLeft: leftPos + 200}, 800);
//	});
//	
//	// Timeline Slide Width
//	$('.eventSlide').click(function() {
//		$('.eventSlide.active').not(this).removeClass('active');
//		$(this).toggleClass('active');
//		$(this).toggleClass('');
//	});
//	
//	// Almost works correctly... Sigh.
//	$('.timelineSelector a').click(function () {
//		
//		//reset and highlight the clicked link
//		$('.timelineSelector a').removeClass('selected');
//		$(this).addClass('selected');
//		
//		//grab the current item
//		current = $(this);
//		
//		//scroll it to the destination
//		$('#timelineWrapper').scrollTo($(this).attr('href'), 800);
//		//cancel the link default behavior
//		return false;
//	});

