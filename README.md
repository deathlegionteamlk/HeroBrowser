<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,12,19&height=220&section=header&text=HeroBrowser&fontSize=75&fontColor=ffffff&fontAlignY=38&desc=Chromium-based.%20Gaming%20UI.%20AI%20built%20in.&descAlignY=60&descSize=20&animation=fadeIn" width="100%"/>

<br/>

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=20&duration=2800&pause=900&color=A855F7&center=true&vCenter=true&multiline=true&width=640&height=80&lines=Built+on+Chromium.+Looks+nothing+like+Chrome.;Dark+theme.+Neon+accents.+AI+sidebar.;Desktop+%26+Android+support." alt="Typing animation"/>

<br/><br/>

[![License](https://img.shields.io/badge/License-MIT-a855f7?style=for-the-badge)](./LICENSE)
[![Engine](https://img.shields.io/badge/Engine-Chromium%20%2F%20Qt%20WebEngine-4285F4?style=for-the-badge&logo=googlechrome&logoColor=white)](https://doc.qt.io/qt-5/qtwebengine-index.html)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows%20%7C%20Android-22c55e?style=for-the-badge&logo=android&logoColor=white)](https://github.com/deathlegionteamlk)
[![Built by](https://img.shields.io/badge/💀-Death%20Legion%20Team-1a1a1a?style=for-the-badge)](https://github.com/deathlegionteamlk)

</div>

---

## 🌐 What is HeroBrowser?

Most Chromium-based browsers look like Chrome with a different icon. HeroBrowser doesn't.

It's built on Qt WebEngine — which runs the same Chromium rendering engine as Google Chrome — but the UI is built from scratch with a gaming aesthetic: dark theme, neon accents, a custom sidebar. If you've used Opera GX, you know the vibe. HeroBrowser takes that direction and adds a built-in AI assistant that actually lives inside the browser, not as an extension you bolt on later.

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="600"/>
</div>

---

## ✨ Features

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212257467-871d32b7-e401-42e8-a166-fcfd7baa4c6b.gif" width="80"/>
</div>

<table>
<tr>
<td width="50%">

### 🔵 Chromium Engine
Same rendering engine as Chrome. Full web standards support, hardware-accelerated graphics, and a compatibility baseline you can rely on.

### 🎮 Gaming-Inspired UI
Dark theme with neon accents and a custom sidebar — closer to Opera GX than to a stock browser skin. Built with Qt for native performance.

</td>
<td width="50%">

### 🤖 Death Legion AI Assistant
An AI assistant baked into the browser, not installed as an extension. It can help with what you're reading, writing, or searching — without switching context.

### 📱 Desktop + Android
The project structure supports Android deployment alongside the desktop build. One codebase, two targets.

</td>
</tr>
</table>

---

## 🔨 Build from Source

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212257454-16e3712e-945a-4ca2-b238-408ad0bf87e6.gif" width="80"/>
</div>

### Prerequisites

| Requirement | Version |
|---|---|
| C++ Compiler | C++17 or newer |
| CMake | 3.10+ |
| Qt with WebEngine | 5.15+ |

### Build

```bash
mkdir build
cd build
cmake ..
make
./HeroBrowser
```

That's it. No additional package manager, no multi-step config. Qt WebEngine handles the heavy lifting.

---

## 🏗️ Architecture

```
┌─────────────────────────────────────────────┐
│                 HeroBrowser                 │
│                                             │
│  ┌──────────────┐   ┌─────────────────────┐ │
│  │  Qt UI Layer │   │  Death Legion AI    │ │
│  │  Dark theme  │   │  Assistant sidebar  │ │
│  │  Neon skin   │   │                     │ │
│  └──────┬───────┘   └─────────────────────┘ │
│         │                                   │
│  ┌──────▼───────────────────────────────┐   │
│  │         Qt WebEngine (Chromium)       │   │
│  │   Full web standards · GPU accel     │   │
│  └──────────────────────────────────────┘   │
│                                             │
│  🖥️  Desktop (Linux / Windows)              │
│  📱  Android (project structure ready)      │
└─────────────────────────────────────────────┘
```

---

## 🤝 Contributing

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212284115-f47cd8ff-2ffb-4b04-b5bf-4d1c14c0247f.gif" width="400"/>
</div>

Issues and PRs welcome. If you're adding something significant, open an issue first so we can talk through the direction.

---

## 🛡️ License

MIT © [Death Legion Team](https://github.com/deathlegionteamlk)

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=6,12,19&height=100&section=footer&animation=fadeIn" width="100%"/>

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=13&duration=4000&pause=1000&color=A855F7&center=true&vCenter=true&width=500&lines=Chromium+engine.+Zero+Chrome+vibes.;Built+for+the+ones+who+need+more.;💀+Death+Legion+Team." alt="Footer typing"/>

</div>
