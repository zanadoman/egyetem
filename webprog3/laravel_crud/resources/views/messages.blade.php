<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Messages</title>
</head>
<body>

<p><b>{{ Auth::user()->email }}</b><p>

@foreach ($messages as $message)
    <form action="{{ route('messages.destroy', $message->id) }}" method="POST">
        @csrf
        @method('DELETE')
        <label><b>{{ $message->title }}</b> {{ $message->content }}</label>
        <button type="submit">Delete</button>
    </form>
    <form action="{{ route('messages.update', $message->id) }}" method="POST">
        @csrf
        @method('PUT')
        <label>Title</label>
        <input type="text" name="title" value="{{ $message->title }}" />
        <label>Content</label>
        <input type="text" name="content" value="{{ $message->content }}" />
        <button type="submit">Edit</button>
    </form>
    <br>
@endforeach

<form action="{{ route('messages.store') }}" method="POST">
    @csrf
    @method('POST')
    <label>Title</label>
    <input type="text" name="title" />
    <label>Content</label>
    <input type="text" name="content" />
    <button type="submit">Send</button>
</form>

<br>

<form action="{{ route('logout') }}" method="POST">
    @csrf
    @method('POST')
    <button type="submit">Logout</button>
</form>

</body>
</html>
