# Maintainer: github.com/ssepi0l-pv
pkgname=dwm62
pkgver=1.0
pkgrel=1
pkgdesc="ssepi0l-pv dwm6.2 build"
arch=('any')
url="https://github.com/ssepi0l-pv/dwm6.2"
license=('GPL')
groups=('$USER')
optdepends=('emacs: highly functional and modifiable text editor.'
            'zim: episodic notebook mainly for taking notes.'
            'discord: social media with voice and chat funcs.'
            'ranger: cli-based file manager.'
            'firefox: pretty bloated web browser.'
            'alacritty: terminal emulator with gpu acceleration.'
            'rofi: bloated dmenu.'
            'flameshot: gui app for taking screenshots.'
            'neomutt: cli-based mail application.'
            'keepass: powerful password manager.'
            'htop: top, but bloated.'
            'pavucontrol: gui app for controlling audio.'
            'pamixer: highly functional audio manager. works with pulseaudio.'
            'mpc: the Music Player Controller.'
            'ncmcpp: cli-based music player.'
            'mpd: the Music Player Daemon.')
replaces=('dwm')
install=
changelog=
source=("$pkgname-$pkgver.tar.gz"
        "$pkgname-$pkgver.patch")
noextract=()
md5sums=()
validpgpkeys=()

prepare() {
	cd "$pkgname-$pkgver"
	patch -p1 -i "$srcdir/$pkgname-$pkgver.patch"
}

build() {
	cd "$pkgname-$pkgver"
	./configure --prefix=/usr
	make
}

check() {
	cd "$pkgname-$pkgver"
	make -k check
}

package() {
	cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir/" install
}
