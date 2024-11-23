{
  description = "htop - buit with hjkl for movement";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/release-24.05";
  };

  outputs = { self, nixpkgs }: {

    packages.x86_64-linux.default = let
      pkgs = nixpkgs.legacyPackages.x86_64-linux;
    in
      pkgs.htop.overrideAttrs (oldAttrs: rec {
        pname = "htop-vim";
        version = "3.3-vim";

        patches = [];

        src = ./.;

        meta = {
          inherit (oldAttrs.meta) platforms license;
          description = "An interactive process viewer for Linux, with vim-style keybindings";
          homepage = "https://github.com/metaspace/htop";
          mainProgram = "htop";
        };
      });

  };
}
