<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>???</title>
</head>
<body>
    <header>
        @include('public.main_header')
    </header>
    <nav>
        @include('public.main_menu')
    </nav>
    @yield('dynamic_content')
</body>
</html>
