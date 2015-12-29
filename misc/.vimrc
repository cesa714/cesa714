set smartindent
set tabstop=2
set shiftwidth=2
set expandtab
set nowrap
colorscheme molokai
set hlsearch

syntax on
filetype on
au BufNewFile,BufRead *.tpp set filetype=cpp

:nnoremap <expr> y (v:register ==# '"' ? '"+' : '') . 'y'
:nnoremap <expr> yy (v:register ==# '"' ? '"+' : '') . 'yy'
:nnoremap <expr> Y (v:register ==# '"' ? '"+' : '') . 'Y'
:xnoremap <expr> y (v:register ==# '"' ? '"+' : '') . 'y'
:xnoremap <expr> Y (v:register ==# '"' ? '"+' : '') . 'Y'

:nnoremap <expr> p (v:register ==# '"' ? '"+' : '') . 'p'
:nnoremap <expr> pp (v:register ==# '"' ? '"+' : '') . 'pp'
:nnoremap <expr> P (v:register ==# '"' ? '"+' : '') . 'P'
:xnoremap <expr> p (v:register ==# '"' ? '"+' : '') . 'p'
:xnoremap <expr> P (v:register ==# '"' ? '"+' : '') . 'P'

highlight OverLength ctermbg=red ctermfg=white guibg=#592929
match OverLength /\%81v.\+/
