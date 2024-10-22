<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Categories</title>
</head>
<body>

@foreach ($messages as $message)
    <form action="{{ route('messages.destroy', $message->id) }}" method="POST">
        @csrf
        @method('DELETE')
        <label><b>{{ $message->title }}</b> {{ $message->content }}</label>
        <button type="submit">delete</button>
    </form>
    <form action="{{ route('messages.update', $message->id) }}" method="POST">
        @csrf
        @method('PUT')
        <input type="text" name="title" value="{{ $message->title }}" />
        <input type="text" name="content" value="{{ $message->content }}" />
        <button type="submit">edit</button>
    </form>
    <br>
@endforeach

<form action="{{ route('messages.store') }}" method="POST">
    @csrf
    @method('POST')
    <input type="text" name="title" />
    <input type="text" name="content" />
    <button type="submit">send</button>
</form>

</body>
</html>
