document.addEventListener("DOMContentLoaded", () => {
  const video = document.getElementById("hero-video");

  video.muted = true;
  video.loop = true;
  video.playsInline = true;
  
  function fitVideo() {
    const videoRatio = 16 / 9;
    const containerRatio = video.parentElement.offsetWidth / video.parentElement.offsetHeight;
    
    if (containerRatio > videoRatio) {
      video.style.width = '100%';
      video.style.height = '100%';
      video.style.objectFit = 'cover';
    } else {
      video.style.width = '100%';
      video.style.height = '100%';
      video.style.objectFit = 'cover';
    }
  }

  fitVideo();

  window.addEventListener('resize', fitVideo);

  const playVideo = async () => {
    try {
      await video.play();
      console.log("Video playing");
    } catch (err) {
      console.log("Video autoplay failed:", err);
      
      const playButton = document.createElement("button");
      playButton.innerHTML = "Play";
      playButton.className = "video-play-button";
      video.parentElement.appendChild(playButton);
      
      playButton.addEventListener("click", async () => {
        try {
          await video.play();
          playButton.remove();
        } catch (err) {
          console.log("Manual play failed:", err);
        }
      });
    }
  };

  playVideo();

  document.addEventListener("visibilitychange", () => {
    if (document.hidden) {
      video.pause();
    } else {
      playVideo();
    }
  });
});