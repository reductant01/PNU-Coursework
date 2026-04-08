import { useState, useEffect, useRef } from "react";

export default function BoxOffice() {
  // json data 저장변수
  const [tdata, setTdata] = useState([]); // 배열이라서 []사용
  const [tags, setTags] = useState([]);
  const [selMv, setSelMv] = useState("");
  const inRef = useRef();

  // 데이터 가져오기
  const getData = (() => {
    let tmDt = inRef.current.value.replaceAll("-", "")
    let url = 'https://kobis.or.kr/kobisopenapi/webservice/rest/boxoffice/searchDailyBoxOfficeList.json?';
    url = url + `key=${process.env.REACT_APP_MV}`;
    url = url + `&targetDt=${tmDt}`;

    console.log(url);

    //fetch함수를 이용하여 오픈API 데이터 불러오기
    fetch(url)
      .then(resp => resp.json())
      .then(data => setTdata(data.boxOfficeResult.dailyBoxOfficeList))
      ;
  })

  // 영화가 선택되었을 떄
  const handleSelMv = ((mv) => {
    console.log(mv)
    let tm = <>
      <span className="mr-2">{mv.movieNm}</span>
      <span className="mr-2 text-white">개봉일 : {mv.openDt}</span>
      <span className="mr-2 text-white">
        누적관객수 : {parseInt(mv.audiAcc).toLocaleString()}
      </span>
    </>
    setSelMv(tm)
  })

  // 날짜가 선택되었을 때
  const handleSelDt = ((e) => {
    e.preventDefault();
    console.log(inRef.current.value)
    getData();
  })

  // 컴포넌트 생성시
  useEffect(() => {

  }, []);

  // tdata가 변경될때 실행
  useEffect(() => {
    if (tdata.length == 0) return;

    console.log(tdata)
    let tm = tdata.map(item =>
      <tr className="bg-white border-b hover:bg-gray-50 font-bold hover:cursor-pointer"
        onClick={() => { handleSelMv(item) }}
        key={item.movieCd}>
        {/* 왜 key를 입력하지 않으면 오류발생?? */}
        <th scope="row" className="px-6 py-2 font-medium text-gray-900 whitespace-nowrap dark:text-white">
          {item.rank}
        </th>
        <td className="px-6 py-2">
          {item.movieNm}
        </td>
        <td className="px-6 py-2 text-right">
          {parseInt(item.salesAmt).toLocaleString()}
        </td>
        <td className="px-6 py-2  text-right">
          {parseInt(item.audiCnt).toLocaleString()}
        </td>
        <td className="px-6 py-2">
          {parseInt(item.rankInten) > 0 ? <span className="text-red-600">▲</span>
            : parseInt(item.rankInten) < 0 ? <span className="text-blue-600">▼</span>
              : '-'}
          {/* if 대신 사용*/}
          {parseInt(item.rankInten) != 0 && Math.abs(item.rankInten)}
          {/* Math.abs = 절댓값 */}
        </td>
      </tr>);

    setTags(tm);

  }, [tdata]);

  return (
    <div className="text-black w-10/12
                    relative overflow-x-auto shadow-md sm:rounded-lg
                    ">
      <form className="flex justify-end items-center
                       mb-2
                       text-lg">
        <label htmlFor="dt" className="text-sm mr-5 font-bold">
          날짜선택
        </label>
        <input type="date" id="dt"
          ref={inRef} // input에 ref 속성주기
          onChange={handleSelDt}
          className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block ps-10 p-2.5 " />
      </form>
      <table className="w-full text-sm text-left rtl:text-right text-gray-500">
        <thead className="text-lg text-gray-50 uppercase bg-black">
          <tr>
            <th scope="col" className="px-6 py-3">
              순위
            </th>
            <th scope="col" className="px-6 py-3">
              영화명
            </th>
            <th scope="col" className="px-6 py-3">
              매출액
            </th>
            <th scope="col" className="px-6 py-3">
              관객수
            </th>
            <th scope="col" className="px-6 py-3">
              증감
            </th>
          </tr>
        </thead>
        <tbody>
          {tags}
          {/* tags는 tr을 가지는 코드이다. 바로 실행해도 출력가능 */}
        </tbody>
      </table>
      <div className="flex justify-center items-center
                      px-6 py-2 font-bold
                      text-lg bg-black text-yellow-300">
        {selMv == "" ? "영화정보" : selMv}
      </div>

    </div>
  )
}