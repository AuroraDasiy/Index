// 当用户点击扩展图标时触发
chrome.action.onClicked.addListener((tab) => {
  // 检查当前标签的静音状态并切换
  chrome.tabs.update(tab.id, { muted: !tab.mutedInfo.muted }, () => {
      // 更新图标
      if (tab.mutedInfo.muted) {
          chrome.action.setIcon({ path: "icons/unmute.png", tabId: tab.id });
          chrome.action.setTitle({ title: "Unmute Tab" });
      } else {
          chrome.action.setIcon({ path: "icons/mute.png", tabId: tab.id });
          chrome.action.setTitle({ title: "Mute Tab" });
      }
  });
});
