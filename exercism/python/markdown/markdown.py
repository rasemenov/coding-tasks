import re
from typing import Optional, List


def put_inside_tag(tag: str, line: str) -> str:
    return f'<{tag}>{line}</{tag}>'


def check_for_header(line: str) -> bool:
    # Whitespace indicate the end of the header hashes.
    header_level = line.find(' ')
    # No headers for 7 and more hashes in a row.
    return line.startswith('#') and header_level < 7


def format_header(line: str) -> str:
    header_level = line.find(' ')
    return put_inside_tag(f'h{header_level}', f'{line[header_level+1:]}')


def get_bold_parts(line: str) -> Optional[re.Match]:
    return re.match('(.*)__(.*)__(.*)', line)


def format_to_bold(matched: re.Match) -> str:
    first, second, third = matched.groups()
    return first + put_inside_tag('strong', second) + third


def get_italic_parts(line: str) -> Optional[re.Match]:
    return re.match('(.*)_(.*)_(.*)', line)


def format_to_italic(matched: re.Match) -> str:
    first, second, third = matched.groups()
    return first + put_inside_tag('em', second) + third


def finalize_html_list(html_list: List[str]) -> str:
    # Empty string does not do any harm but this allows to include this
    # condition only in one place instead of before every call.
    if len(html_list) == 0:
        return ''
    html_list[0] = '<ul>' + html_list[0]
    html_list[-1] = html_list[-1] + '</ul>'
    return ''.join(html_list)


def adjust_font(line: str) -> str:
    bold_group = get_bold_parts(line)
    if bold_group:
        line = format_to_bold(bold_group)
    italic_group = get_italic_parts(line)
    if italic_group:
        line = format_to_italic(italic_group)
    return line


def parse(markdown: str) -> str:
    lines = markdown.split('\n')
    res = []
    html_list = []
    for line in lines:
        is_header = check_for_header(line)
        if is_header:
            line = format_header(line)
        line = adjust_font(line)
        list_group = re.match(r'\* (?P<item>.*)', line)
        is_list = list_group is not None
        if is_list:
            curr = list_group.group('item')
            line = put_inside_tag('li', curr)
            html_list.append(line)
        if not is_header and not is_list:
            line = put_inside_tag('p', line)
            res.append(finalize_html_list(html_list))
            html_list = []
        if not is_list:
            res.append(line)
    res.append(finalize_html_list(html_list))
    return ''.join(res)
