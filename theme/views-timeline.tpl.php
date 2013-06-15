<div class="debug" id="debug">
<pre>
<!-- Debug section -->
</pre>
</div>
<div class="container">
			<div class="timelineContainer">
				<div class="timelineControls">
					<a href="#" class="btnPrevious">&larr;</a>
					<a href="#" class="btnNext">&rarr;</a>
				</div><!-- /.timelineControls -->
				
				<div class="timelineWrapper">
					<ol class="timelineSlider">
					<?php $yearNav = ''; ?>
						<?php foreach($result as $key => $event) :?>
						<li class="eventSlide year<?php echo $event['date'];?>" id="year<?php echo $event['date'];?>" >
							<div class="image">
							
								<img src="<?php print file_create_url($event['image']['uri']); ?>" alt="<?php print $event['image']['alt']; ?> IMAGE" />
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
						<?php $yearNav .= "<li><a href=''>" . $event['date'] ."</a></li>\n" ;?>
						<?php endforeach;?>
						
					</ol>
				</div><!-- /.timelineWrapper -->
				
				<ol class="timelineSelector">
					<li class="prev">&larr;</li>
					<?php print $yearNav; ?>
					<li class="next">&rarr;</li>
				</ol><!-- /.timelineSelector-->
			</div><!-- /.timelineContainer -->
		</div><!-- /.container -->
			
		</script>
