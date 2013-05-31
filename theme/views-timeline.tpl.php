<div class="debug">
<pre>
<?php dsm($node); ?>
</pre>
</div>
------------
<div class="container">
			<div class="timelineContainer">
				
				<div class="timelineControls">
					<a href="#" class="btnPrevious">&larr;</a>
					<a href="#" class="btnNext">&rarr;</a>
				</div><!-- /.timelineControls -->
				
				<div class="timelineWrapper">
					<ol class="timelineSlider">
						<?php foreach($result as $key => $event) :?>
						<li class="eventSlide" id="year1785">
							<div class="image">
								<img src="<?php print $event['image']['uri']; ?>" alt="<?php print $event['image']['alt']; ?>" />
								<p class="caption">
									<?php print $event['image']['caption']; ?>
								</p>
							</div>
							<div class="text">
								<h6 class="date"><?php print $event['date']; ?></h6>
								<h5 class="title"><?php print $event['title']; ?></h5>
								<p class="desc">
									<?php print $event['desc']; ?>
								</p>
							</div>
						</li>
						<?php endforeach;?>
						
						
					</ol>
				</div><!-- /.timelineWrapper -->
				
				<ol class="timelineSelector">
					<li class="prev">&larr;</li>
					<li><a href="#year1785">1785</a></li>
					<li><a href="#year1920">1920</a></li>
					<li><a href="#year1930">1930</a></li>
					<li><a href="#year1940">1940</a></li>
					<li><a href="#year1950">1950</a></li>
					<li class="disabled"><a href="#year1960">1960</a></li>
					<li class="disabled"><a href="#year1970">1970</a></li>
					<li class="disabled"><a href="#year1980">1980</a></li>
					<li class="disabled"><a href="#year1990">1990</a></li>
					<li class="disabled"><a href="#year2000">2000</a></li>
					<li class="disabled"><a href="#year2010">2010</a></li>
					<li class="next">&rarr;</li>
				</ol><!-- /.timelineSelector-->
			</div><!-- /.timelineContainer -->
		</div><!-- /.container -->
		
		<!--  
		<script src="jquery.easing.1.3.js"></script>
		<script>
			
			// Timeline Controls
			$('.timelineControls a.btnPrevious').click(function () { 
				var leftPos = $('.timelineWrapper').scrollLeft();
				$('.timelineWrapper').animate({scrollLeft: leftPos - 200}, 800);
			});
			$('.timelineControls a.btnNext').click(function () { 
				var leftPos = $('.timelineWrapper').scrollLeft();
				$( '.timelineWrapper' ).animate({scrollLeft: leftPos + 200}, 800);
			});
			
			// Timeline Slide Width
			$('.eventSlide').click(function() {
				$('.eventSlide.active').not(this).removeClass('active');
				$(this).toggleClass('active');
				$(this).toggleClass('');
			});
			-->
			
			
			// Almost works correctly... Sigh.
			$('.timelineSelector a').click(function () {
				
				//reset and highlight the clicked link
				$('.timelineSelector a').removeClass('selected');
				$(this).addClass('selected');
				
				//grab the current item
				current = $(this);
				
				//scroll it to the destination
				$('#timelineWrapper').scrollTo($(this).attr('href'), 800);
				//cancel the link default behavior
				return false;
			});
			
		</script>
