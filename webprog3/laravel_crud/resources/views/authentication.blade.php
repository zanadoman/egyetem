<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Authentication</title>
</head>
<body>

<form action="{{ route('registration.store') }}" method="POST">
    @csrf
    @method('POST')
    <label>E-mail</label>
    <input type="text" name="email" />
    <label>Password</label>
    <input type="password" name="password" />
    <button type="submit">Register</button>
</form>

<form action="{{ route('login.store') }}" method="POST">
    @csrf
    @method('POST')
    <label>E-mail</label>
    <input type="text" name="email" />
    <label>Password</label>
    <input type="password" name="password" />
    <button type="submit">Login</button>
</form>

@if ($errors->any())
    @foreach ($errors->all() as $error)
        <p>{{ $error }}</p>
    @endforeach
@endif

</body>
</html>
